// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>

#include "MemoryMgr.h"
#include "b3d.h"


using namespace Memory::VP;
using namespace Blitz3D;

void WINAPI null_func() {}

// dump funcs
void WINAPI  RegisterBlitz3DFunction(char* name, int addr)
{
	printf("%s | [0x%X]\n", name, addr);
}


int image = 0;
int texture = 0;
int camera = 0;
int cube = 0;

void WINAPI NewGraphics(int x, int y, int bits, eGraphicModes g_mode)
{
	g_mode = GRAPHICS_MODE_WINDOWED;
	x = 640;
	y = 480;
	Blitz3D::Graphics3D(1024,768, 32, GRAPHICS_MODE_WINDOWED);
//	Blitz3D::Graphics(x, y, bits, GRAPHICS_MODE_WINDOWED_SCALED);

	image = CreateImage(1024,768);
	texture = CreateTexture(640, 480);

	if (image)
	{
		printf("Buffer set!\n");
		SetBuffer(ImageBuffer(image));
	}
	else
		printf("Failed to create image\n");

	if (texture)
		printf("texture ok!\n");

	int camera = CreateCamera();
	AmbientLight(255, 255, 255);

	//

}

bool flip = false;

void WINAPI NewUpdateWorld(int wait)
{
	int img_buffer = ImageBuffer(image);
	// fixes a crash for some reason
	LockBuffer(img_buffer);
	UnlockBuffer(img_buffer);

	SetBuffer(BackBuffer());
	Cls();


	if (!cube)
	{
		cube = CreateCube();

		if (cube)
			printf("3D ok! %x\n",cube);

		PositionEntity(cube, 0, 0, 4);
		ScaleEntity(cube, 2,1,1);
		EntityTexture(cube, texture);

	}
	TurnEntity(cube, 0.1, 0.1, 0.1);
	CopyRect(0, 0, 640, 480, 0, 0, ImageBuffer(image), TextureBuffer(texture));
	//DrawImage(image, 0, 0);
	SetBuffer(img_buffer);
	UpdateWorld();
	RenderWorld();
	Flip(wait);
}

void Init()
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	Patch<int>(0x1002A4E9 + 1, (int)NewGraphics);
	Patch<int>(0x1002A4F5 + 1, (int)NewGraphics);
	// get control of buffer
	Patch<int>(0x1002A5B5 + 1, (int)null_func);
	Nop(0x10025BAD, 5);
	Nop(0x1002A0E3, 5);
	Patch<int>(0x1002A585 + 1, (int)NewUpdateWorld);
	//InjectHook(0x100010EA, RegisterBlitz3DFunction, PATCH_JUMP);

}


extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		Init();
	}
}

