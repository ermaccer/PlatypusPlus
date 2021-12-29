#pragma once

enum eGraphicModes {
	GRAPHICS_MODE_AUTO,
	GRAPHICS_MODE_FULLSCREEN,
	GRAPHICS_MODE_WINDOWED,
	GRAPHICS_MODE_WINDOWED_SCALED
};


namespace Blitz3D {
	void __stdcall Graphics3D(int width, int height, int depth, eGraphicModes mode);
	void __stdcall Graphics(int width, int height, int depth, eGraphicModes mode);

	void __stdcall CameraZoom(int camera, float zoom);
	void __stdcall CameraViewport(int camera, int x, int y, int width, int height);
	void __stdcall CameraProjMode(int camera, int mode);
	void __stdcall CameraClsColor(int camera, int red, int green, int blue);
	int  GraphicsWidth();
	int  GraphicsHeight();

	void __stdcall SetBuffer(int buffer);
	void __stdcall SaveBuffer(int buffer, int path);

	void __stdcall LockBuffer(int buffer);
	void __stdcall UnlockBuffer(int buffer);
	int  BackBuffer();

	//CopyRect%source_x%source_y%width%height%dest_x%dest_y%src_buffer=0%dest_buffer=0 | [0x10026580]
	void __stdcall CopyRect(int source_x, int source_y, int width, int height, int dest_x, int dest_y, int src_buffer = 0, int dest_buffer = 0);


	// image

	int __stdcall _LoadImage(int image);
	void __stdcall DrawImage(int image, int x, int y, int frame = 0);
	void __stdcall ScaleImage(int image, float x, float y);
	void __stdcall ResizeImage(int image, float x, float y);
	int __stdcall CreateImage(int x, int y, int frames = 1);
	int __stdcall ImageBuffer(int image, int frame = 0);
	int __stdcall ImageWidth(int image);
	int __stdcall ImageHeight(int image);
	//textures
	int __stdcall CreateTexture(int x, int y, int flags = 0, int frames = 1);
	int __stdcall TextureBuffer(int image, int frame = 0);
	void __stdcall ScaleTexture(int image, float x, float y);
	// world
	void __stdcall UpdateWorld(float elapsed_time = 1);
	void __stdcall RenderWorld(float tween = 1);
	void __stdcall Flip(int vwait = 1);
	// core
	int __stdcall _bbCStrToStr(char* str);
	void __stdcall ClsColor(int red, int green, int blue);
	void __stdcall Cls();

	// 3d
	// %CreateCube%parent=0 
	void __stdcall AmbientLight(float red, float green, float blue);
	int __stdcall CreateCamera(int parent = 0);
	int __stdcall CreateCube(int parent = 0);
	int __stdcall CreateMesh(int parent = 0);
	int __stdcall CreatePlane(int segments = 1, int parent = 0);
	int __stdcall CreateSurface(int mesh, int brush = 0);

	void __stdcall EntityColor(int entity, float r, float g, float b);
	void __stdcall ScaleEntity(int entity, float x, float y, float z, int global = true);
	void __stdcall PositionEntity(int entity, float x, float y, float z, int global = true);
	void __stdcall RotateEntity(int entity, float x, float y, float z, int global = true);
	void __stdcall TurnEntity(int entity, float x, float y, float z, int global = true);
	void __stdcall EntityTexture(int entity, int texture, int frame = 0, int index = 0);

	// 3d commands
	//%AddVertex%surface#x#y#z#u=0#v=0#w=1 | [0x1000ED80]
	//%AddTriangle%surface%v0%v1%v2 | [0x1000EE40]
	//
	void __stdcall AddVertex(int surface, float x, float y, float z, float u = 0, float v = 0, float w = 1);
	void __stdcall AddTriangle(int surface, int v1, int v2, int v3);
	//%surface%index#u#v#w=1%coord_set=0 | [0x1000F090]
	void __stdcall VertexTexCoords(int surface, int index, float u, float v, float w = 1, int coord_set = 0);
	void __stdcall UpdateNormals(int mesh);


	void DrawImageScale(int image, int x, int y, int w, int h);
}

