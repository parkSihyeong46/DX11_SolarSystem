#pragma once
#include "framework.h"
#include "resource.h"
#include <D3D11.h>

class GraphicClass;
class CameraClass;
class SystemClass
{
private:
	HWND m_hWnd;
	HINSTANCE m_hInst;
	const char* m_className = "SolarSystemClass";
	GraphicClass* graphicClass = NULL;
	CameraClass* cameraClass = NULL;

public:
	HRESULT InitWindow(int& nCmdShow);
	void Run();
	void Shutdown();

	HWND* GetHwnd();

};

static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);