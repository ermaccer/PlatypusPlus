#pragma once

#define MENU_FOV 92.0f
#define GAME_FOV 139.0f
#define MIRROR_FOV 325.0f


enum eGraphicModes {
	GRAPHICS_MODE_AUTO,
	GRAPHICS_MODE_FULLSCREEN,
	GRAPHICS_MODE_WINDOWED,
	GRAPHICS_MODE_WINDOWED_SCALED
};

struct Blitz3DModel {
	int ptr;
	char* modelName;
};


struct ImageCache{
	int ptr;
bool scaled;
};

namespace Blitz3D {
	void __stdcall Graphics3D(int width, int height, int depth, eGraphicModes mode);
	void __stdcall Graphics(int width, int height, int depth, eGraphicModes mode);
	int  GraphicsWidth();
	int  GraphicsHeight();

	void __stdcall SetBuffer(int buffer);
	void __stdcall SaveBuffer(int buffer, int path);

	void __stdcall LockBuffer(int buffer);
	void __stdcall UnlockBuffer(int buffer);
	int  BackBuffer();

	//CopyRect%source_x%source_y%width%height%dest_x%dest_y%src_buffer=0%dest_buffer=0 | [0x10026580]
	void __stdcall CopyRect(int source_x, int source_y, int width, int height, int dest_x, int dest_y, int src_buffer, int dest_buffer);


	// image

	int __stdcall _LoadImage(int image);
	void __stdcall DrawImage(int image, int x, int y, int frame = 0);
	void __stdcall ScaleImage(int image, float x, float y);
	void __stdcall ResizeImage(int image, float x, float y);
	int __stdcall CreateImage(int x, int y, int frames = 1);
	int __stdcall ImageBuffer(int image, int frame = 0);

	//textures
	int __stdcall CreateTexture(int x, int y, int flags = 0, int frames = 1);
	int __stdcall TextureBuffer(int image, int frame = 0);
	// world
	void __stdcall UpdateWorld(float elapsed_time = 1);
	void __stdcall RenderWorld(float tween = 1);
	void __stdcall Flip(int vwait = 1);
	// core
	int __stdcall _bbCStrToStr(char* str);
	void __stdcall Cls();

	// 3d
	// %CreateCube%parent=0 
	void __stdcall AmbientLight(float red, float green, float blue);
	int __stdcall CreateCamera(int parent = 0);
	int __stdcall CreateCube(int parent = 0);

	void __stdcall EntityColor(int entity, float r, float g, float b);
	void __stdcall ScaleEntity(int entity, float x, float y, float z, int global = true);
	void __stdcall PositionEntity(int entity, float x, float y, float z, int global = true);
	void __stdcall RotateEntity(int entity, float x, float y, float z, int global = true);
	void __stdcall TurnEntity(int entity, float x, float y, float z, int global = true);
	void __stdcall EntityTexture(int entity, int texture, int frame = 0, int index = 0);
}
