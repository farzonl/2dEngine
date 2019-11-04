#include "pch.h"
#include "MainModule.h"
#include "WindowMgr.h"
#include "ManagedLayer.h"

void WINAPI NoFill() {
	WindowMgr::noFill();
}

int WINAPI Width() {
	return WindowMgr::getWidth();
}

int WINAPI Height() {
	return WindowMgr::getHeight();
}

void WINAPI NoStroke() {
	WindowMgr::noStroke();
}

void WINAPI Stroke(float r, float g, float b) {
	WindowMgr::stroke(r, g, b);
}

void WINAPI Rotate(float degrees) {
	WindowMgr::rotate(degrees);
}

// extent is the processing word for radius
void WINAPI Circle(float x, float y, float extent) {
	WindowMgr::ellipse(x, y, extent, extent);
}

void WINAPI Square(float x, float y, float extent) {
	WindowMgr::rect(x, y, extent, extent);
}

void WINAPI Rect(float x, float y, float width, float height) {
	WindowMgr::rect(x, y, width, height);
}

void WINAPI Quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	WindowMgr::quad(x1, y1, x2, y2, x3, y3, x4, y4);
}

void WINAPI Line(float x1, float y1, float x2, float y2) {
	WindowMgr::line(x1, y1, x2, y2);
}

void WINAPI Triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
	WindowMgr::triangle(x1, y1, x2, y2, x3, y3);
}


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
	Setup();
	bool result = WindowMgr::initWindow();
	if (!result) {
		// TODO add failure message
		return;
	}
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