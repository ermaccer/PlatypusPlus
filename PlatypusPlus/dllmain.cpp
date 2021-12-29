// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <vector>
#include <d3d9.h>
#include <algorithm>
#include <windowsx.h>

#include "resource.h"

#include "MemoryMgr.h"
#include "ePlatypusPlus.h"

EXTERN_C IMAGE_DOS_HEADER __ImageBase;


using namespace Memory::VP;
using namespace Blitz3D;


std::vector<video_mode> resolutions;

bool mode_compare(video_mode first, video_mode in)
{
	return first.height == in.height && first.width == in.width;
}


void GetVideoModes()
{
	IDirect3D9* dev = Direct3DCreate9(D3D_SDK_VERSION);

	if (dev)
	{
		for (unsigned int i = 0; i < dev->GetAdapterModeCount(0, D3DFMT_X8R8G8B8); i++)
		{
			D3DDISPLAYMODE mode;

			if (SUCCEEDED(dev->EnumAdapterModes(0, D3DFMT_X8R8G8B8, i, &mode)))
			{
				video_mode v_mode;
				v_mode.width = mode.Width;
				v_mode.height = mode.Height;
				v_mode.format = mode.Format;
				v_mode.refRate = mode.RefreshRate;
				resolutions.push_back(v_mode);
			}

		}
		auto pos = std::unique(resolutions.begin(), resolutions.end(), mode_compare);
		resolutions.erase(pos, resolutions.end());

		dev->Release();
		dev = nullptr;
	}
	else
	{
		MessageBox(0, L"Failed to create Direct3D device!", L"Error", MB_ICONERROR);
	}
}


void WriteValue(int mode, const char* key)
{
	char value[64] = {};
	sprintf_s(value, "%d", mode);
	WritePrivateProfileStringA("Settings", key, value, ".\\platypus.ini");
}


INT_PTR CALLBACK Launcher(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		DWORD res;
		HWND list;
		CheckDlgButton(hDlg, FULLSCREEN, TRUE);
		res = GetPrivateProfileIntA("Settings", "VideoMode", 0, ".\\platypus.ini");
		ePlatypusPlus::m_bUseFullscreenMode = GetPrivateProfileIntA("Settings", "Fullscreen", 1, ".\\platypus.ini");

		if (res > resolutions.size())
			res = 0;

		list = GetDlgItem(hDlg, RESOLUTION);
		SendMessage(list, CB_RESETCONTENT, 0, 0);

		for (unsigned int i = 0; i < resolutions.size(); i++)
		{
			wchar_t tmp[128] = {};
			wsprintf(tmp, L"%d x %d", resolutions[i].width, resolutions[i].height);
			ComboBox_AddString(list, tmp);
		}
		ComboBox_SetCurSel(list, res);

		CheckDlgButton(hDlg, FULLSCREEN, ePlatypusPlus::m_bUseFullscreenMode);
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			DWORD mode;
			mode = ComboBox_GetCurSel(GetDlgItem(hDlg, RESOLUTION));
			ePlatypusPlus::m_vmSelectedMode = resolutions[mode];
			ePlatypusPlus::m_bUseFullscreenMode = IsDlgButtonChecked(hDlg, FULLSCREEN);
			WriteValue(mode, "VideoMode");
			WriteValue(ePlatypusPlus::m_bUseFullscreenMode, "Fullscreen");

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			WriteValue(ComboBox_GetCurSel(GetDlgItem(hDlg, RESOLUTION)), "VideoMode");
			WriteValue(ePlatypusPlus::m_bUseFullscreenMode, "Fullscreen");
			exit(0);
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void Init()
{
	wchar_t	 moduleName[MAX_PATH] = {};
	GetModuleFileName((HINSTANCE)&__ImageBase, moduleName, MAX_PATH);
	GetVideoModes();
	DialogBox(GetModuleHandle(moduleName), MAKEINTRESOURCE(IDD_DIALOG1), 0, Launcher);
	ePlatypusPlus::Initialize();
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		Init();
	}
}

