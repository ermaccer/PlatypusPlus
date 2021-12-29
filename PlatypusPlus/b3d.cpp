#include "b3d.h"
#include <math.h>
#include <iostream>


void __stdcall Blitz3D::Graphics3D(int width, int height, int depth, eGraphicModes mode)
{
	((void(__stdcall*)(int,int,int,eGraphicModes))0x100258C0)(width,height,depth,mode);
}

void __stdcall Blitz3D::Graphics(int width, int height, int depth, eGraphicModes mode)
{
	((void(__stdcall*)(int, int, int, eGraphicModes))0x10025660)(width, height, depth, mode);
}

void __stdcall Blitz3D::CameraZoom(int camera, float zoom)
{
	((void(__stdcall*)(int, float))0x1000FC80)(camera, zoom);
}

void __stdcall Blitz3D::CameraViewport(int camera, int x, int y, int width, int height)
{
	((void(__stdcall*)(int, int, int, int, int))0x10010120)(camera, x, y, width, height);
}

void __stdcall Blitz3D::CameraProjMode(int camera, int mode)
{
	((void(__stdcall*)(int, int))0x10010040)(camera, mode);
}

void __stdcall Blitz3D::CameraClsColor(int camera, int red, int green, int blue)
{
	((void(__stdcall*)(int, int, int, int))0x1000FE50)(camera, red, green, blue);
}

int Blitz3D::GraphicsWidth()
{
	return ((int(__cdecl*)())0x10026270)();
}

int Blitz3D::GraphicsHeight()
{
	return ((int(__cdecl*)())0x10026280)();
}

void __stdcall Blitz3D::SetBuffer(int buffer)
{
	((void(__stdcall*)(int))0x10024710)(buffer);
}

void __stdcall Blitz3D::SaveBuffer(int buffer, int path)
{
	((void(__stdcall*)(int, int))0x100250D0)(buffer, path);
}

void __stdcall Blitz3D::LockBuffer(int buffer)
{
	((void(__stdcall*)(int))0x10025F20)(buffer);
}

void __stdcall Blitz3D::UnlockBuffer(int buffer)
{
	((void(__stdcall*)(int))0x10025F90)(buffer);
}

int Blitz3D::BackBuffer()
{
	return ((int(__cdecl*)())0x10025F10)();
}

void __stdcall Blitz3D::CopyRect(int source_x, int source_y, int width, int height, int dest_x, int dest_y, int src_buffer, int dest_buffer)
{
	((void(__stdcall*)(int, int, int, int, int, int, int, int))0x10026580)(source_x, source_y, width, height, dest_x, dest_y, src_buffer, dest_buffer);
}

int __stdcall Blitz3D::_LoadImage(int image)
{
	int img = ((int(__stdcall*)(int))0x10026980)(image);
	return img;
}

void __stdcall Blitz3D::DrawImage(int image, int x, int y, int frame)
{
	((void(__stdcall*)(int, int, int, int))0x10027900)(image, x, y, frame);
}

void __stdcall Blitz3D::ScaleImage(int image, float x, float y)
{
	((void(__stdcall*)(int, float, float))0x10028DF0)(image, x, y);
}

void __stdcall Blitz3D::ResizeImage(int image, float x, float y)
{
	((void(__stdcall*)(int, float, float))0x10028EF0)(image, x, y);
}

int __stdcall Blitz3D::CreateImage(int x, int y, int frames)
{
	return ((int(__stdcall*)(int,int,int))0x10027180)(x,y,frames);
}

int __stdcall Blitz3D::ImageBuffer(int image, int frame)
{
	return ((int(__stdcall*)(int, int))0x10027820)(image, frame);
}

int __stdcall Blitz3D::ImageWidth(int image)
{
	return ((int(__stdcall*)(int))0x10028340)(image);
}

int __stdcall Blitz3D::ImageHeight(int image)
{
	return ((int(__stdcall*)(int))0x10028420)(image);
}

int __stdcall Blitz3D::CreateTexture(int x, int y, int flags, int frames)
{
	return ((int(__stdcall*)(int, int, int, int))0x1000A6F0)(x, y, flags, frames);
}

int __stdcall Blitz3D::TextureBuffer(int image, int frame)
{
	return ((int(__stdcall*)(int, int))0x1000B0C0)(image, frame);
}

void __stdcall Blitz3D::ScaleTexture(int image, float x, float y)
{
	((void(__stdcall*)(int, float, float))0x1000AAC0)(image, x, y);
}

void __stdcall Blitz3D::UpdateWorld(float elapsed_time)
{
	((int(__stdcall*)(float))0x1000A200)(elapsed_time);
}

void __stdcall Blitz3D::RenderWorld(float tween)
{
	((int(__stdcall*)(float))0x1000A2B0)(tween);
}

void __stdcall Blitz3D::Flip(int vwait)
{
	((void(__stdcall*)(int))0x10026230)(vwait);
}

int __stdcall Blitz3D::_bbCStrToStr(char * str)
{
	return ((int(__stdcall*)(char*))0x10009580)(str);
}

void __stdcall Blitz3D::ClsColor(int red, int green, int blue)
{
	((void(__stdcall*)(int, int ,int))0x100263B0)(red, green, blue);
}

void __stdcall Blitz3D::Cls()
{
	((void(__stdcall*)())0x10026440)();
}

void __stdcall Blitz3D::AmbientLight(float red, float green, float blue)
{
	((void(__stdcall*)(float, float, float))0x1000A0D0)(red, green, blue);
}

int __stdcall Blitz3D::CreateCamera(int parent)
{
	return ((int(__stdcall*)(int))0x1000FAB0)(parent);
}

int __stdcall Blitz3D::CreateCube(int parent)
{
	return ((int(__stdcall*)(int))0x1000C6A0)(parent);
}

int __stdcall Blitz3D::CreateMesh(int parent)
{
	return ((int(__stdcall*)(int))0x1000BD00)(parent);
}

int __stdcall Blitz3D::CreatePlane(int segments, int parent)
{
	return ((int(__stdcall*)(int, int))0x100128C0)(segments, parent);
}

int __stdcall Blitz3D::CreateSurface(int mesh, int brush)
{
	return ((int(__stdcall*)(int,int))0x1000E830)(mesh, brush);
}

void __stdcall Blitz3D::EntityColor(int entity, float r, float g, float b)
{
	((void(__stdcall*)(int, float, float, float))0x10016250)(entity, r, g, b);
}

void __stdcall Blitz3D::ScaleEntity(int entity, float x, float y, float z, int global)
{
	((void(__stdcall*)(int, float, float, float, int))0x10019970)(entity, x, y, z, global);
}

void __stdcall Blitz3D::PositionEntity(int entity, float x, float y, float z, int global)
{
	((void(__stdcall*)(int, float, float, float, int))0x10019870)(entity, x, y, z, global);
}

void __stdcall Blitz3D::RotateEntity(int entity, float x, float y, float z, int global)
{
	((void(__stdcall*)(int, float, float, float, int))0x10019A70)(entity, x, y, z, global);
}

void __stdcall Blitz3D::TurnEntity(int entity, float x, float y, float z, int global)
{
	((void(__stdcall*)(int, float, float, float, int))0x10019440)(entity, x, y, z, global);
}

void __stdcall Blitz3D::EntityTexture(int entity, int texture, int frame, int index)
{
	((void(__stdcall*)(int, int, int, int))0x10016510)(entity, texture, frame, index);
}

void __stdcall Blitz3D::AddVertex(int surface, float x, float y, float z, float u, float v, float w)
{
	((void(__stdcall*)(int, float, float, float, float, float, float))0x1000ED80)(surface, x, y,z, u,v,w);
}

void __stdcall Blitz3D::AddTriangle(int surface, int v1, int v2, int v3)
{
	((void(__stdcall*)(int, int, int, int))0x1000EE40)(surface, v1,v2,v3);
}

void __stdcall Blitz3D::VertexTexCoords(int surface, int index, float u, float v, float w, int coord_set)
{
	((void(__stdcall*)(int, int, float, float, float, int))0x1000F090)(surface, index, u, v, w, coord_set);
}

void __stdcall Blitz3D::UpdateNormals(int mesh)
{
	((void(__stdcall*)(int))0x1000DDE0)(mesh);
}

void Blitz3D::DrawImageScale(int image, int x, int y, int w, int h)
{
	int ih = 480;
	int iw = 640;
	
	int sw = abs(w);
	int sh = abs(h);

	static int pad = CreateImage(sw, sh);


	float xr = (float)iw / (float)sw;
	float yr = (float)ih / (float)sh;

	int from = ImageBuffer(image);
	int to = ImageBuffer(pad);

	int vf = -1 + ((h > 0) * 2);
	int fw = (w < 0)*w;
	int fh = (h < 0)*h;

	for (int i = 0; i < sw; i++)
		CopyRect(i*xr, 0, 1, ih, i, 0, from, to);

	for (int i = 0; i < sh; i++)
		CopyRect(0, i*yr, sw, 1, x + fw, y + (i*vf), to);


	//DrawImage(pad, 0, 0);
}
