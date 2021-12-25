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

int __stdcall Blitz3D::CreateTexture(int x, int y, int flags, int frames)
{
	return ((int(__stdcall*)(int, int, int, int))0x1000A6F0)(x, y, flags, frames);
}

int __stdcall Blitz3D::TextureBuffer(int image, int frame)
{
	return ((int(__stdcall*)(int, int))0x1000B0C0)(image, frame);
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
