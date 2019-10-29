#include "pch.h"
#include "MainModule.h"
#include "WindowMgr.h"
#include "ManagedLayer.h"

void WINAPI Size(int width, int height) {
	WindowMgr::setSize(width, height);
}

void WINAPI Fill(float r, float g, float b) {
	WindowMgr::setColor(r, g, b);
}

void WINAPI Ellipse(float x, float y, float width, float height) {
	WindowMgr::ellipse(x, y, width, height);
}

void WINAPI Background(float r, float g, float b) {
	WindowMgr::clear(r, g, b);
}

void WINAPI RunLoop() {
	bool result = WindowMgr::initWindow();
	if (!result) {
		// TODO add failure message
		return;
	}
	Setup();
	ShowWindow(WindowMgr::getHwnd(), SW_SHOWNORMAL);
	MSG msg;
	msg.message = WM_NULL;
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			DispatchMessage(&msg);
		}
		else {
			WindowMgr::draw(Draw);
		}
	}
}