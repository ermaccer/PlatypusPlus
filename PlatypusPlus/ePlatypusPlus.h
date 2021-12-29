#pragma once
#include <Windows.h>
#include "b3d.h"

struct video_mode
{
	unsigned int   width;
	unsigned int   height;
	unsigned int   depth;
	unsigned int   refRate;
	unsigned int   format;

};


class ePlatypusPlus {
public:
	static bool m_bUseSoftwareResizing;
	static bool m_bUseFullscreenMode;
	static bool m_bUseXInputSupport;
	static video_mode m_vmSelectedMode;

	// blitz3d resources
	static int m_pImage;


	static void Initialize();

	static void EmptyFunction();
	static void InitializeBlitz3DResources();

	// blitz3d hooks
	static void WINAPI Graphics(int width, int height, int bits, eGraphicModes mode);
	static void WINAPI Flip(int vwait = 1);
};