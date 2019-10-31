#include "pch.h"
#include "panel.h"
#include "ManagedLayer.h"

namespace {
	LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
		switch (uMsg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return S_OK;
		case WM_LBUTTONDOWN:
			int xPos = GET_X_LPARAM(lparam);
			int yPos = GET_Y_LPARAM(lparam);
			MousePressed(xPos, yPos);
			return S_OK;

		}
		return DefWindowProc(hwnd, uMsg, wparam, lparam);
	}
}


bool Panel::makeWindow(HINSTANCE hinstance, LPCWSTR windowName, RECT &r, HWND& hwnd) {
	WNDCLASSEX winClass;
	UINT cbsize = sizeof(winClass);
	ZeroMemory(&winClass, cbsize);
	winClass.cbSize = cbsize;
	winClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	winClass.hInstance = hinstance;
	winClass.lpfnWndProc = ::WindowProc;
	winClass.lpszClassName = windowName;
	winClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&winClass);
	auto width = r.right;
	auto height = r.bottom;
	if (r.right != CW_USEDEFAULT && r.left != CW_USEDEFAULT &&
		r.bottom != CW_USEDEFAULT && r.top != CW_USEDEFAULT) {
		AdjustWindowRectEx(&r, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);
		width = r.right - r.left;
		height = r.bottom - r.top;
	}
	hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, windowName, windowName, WS_OVERLAPPEDWINDOW,
						 0, 0, width, height, nullptr, nullptr, hinstance, 0);

	
	return true;
}