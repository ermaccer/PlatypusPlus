#include "ePlatypusPlus.h"
#include "MemoryMgr.h"

bool ePlatypusPlus::m_bUseSoftwareResizing = true;
bool ePlatypusPlus::m_bUseFullscreenMode = false;
bool ePlatypusPlus::m_bUseXInputSupport = false;
int  ePlatypusPlus::m_pImage = 0;
video_mode ePlatypusPlus::m_vmSelectedMode = {};
using namespace Memory::VP;

void ePlatypusPlus::Initialize()
{
	// get control of buffer
	Patch<int>(0x1002A5B5 + 1, (int)EmptyFunction);
	Nop(0x10025BAD, 5);
	Nop(0x1002A0E3, 5);

	// replace 2d loop
	Patch<int>(0x1002A585 + 1, (int)Flip);

	// replace graphics init
	Patch<int>(0x1002A4E9 + 1, (int)Graphics);
	Patch<int>(0x1002A4F5 + 1, (int)Graphics);
}

void ePlatypusPlus::EmptyFunction()
{
}

void ePlatypusPlus::InitializeBlitz3DResources()
{
	m_pImage = Blitz3D::CreateImage(640, 480);
	if (!m_pImage)
		MessageBox(0, L"Failed to create image!", L"PlatypusPlus", MB_ICONERROR);
}

void __stdcall ePlatypusPlus::Graphics(int width, int height, int bits, eGraphicModes mode)
{
	if (!m_bUseFullscreenMode)
		mode = GRAPHICS_MODE_WINDOWED;

	Blitz3D::Graphics(m_vmSelectedMode.width, m_vmSelectedMode.height, 32, mode);
	InitializeBlitz3DResources();
}

void __stdcall ePlatypusPlus::Flip(int vwait)
{
	int img_buffer = Blitz3D::ImageBuffer(m_pImage);
	// fixes a crash for some reason
	Blitz3D::LockBuffer(img_buffer);
	Blitz3D::UnlockBuffer(img_buffer);

	Blitz3D::SetBuffer(Blitz3D::BackBuffer());
	Blitz3D::Cls();

	Blitz3D::DrawImageScale(m_pImage, 0, 0, Blitz3D::GraphicsWidth(), Blitz3D::GraphicsHeight());

	Blitz3D::SetBuffer(img_buffer);
	Blitz3D::Flip(vwait);
}
