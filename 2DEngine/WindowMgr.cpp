#include "pch.h"
#include "WindowMgr.h"
#include "Singleton.h"
#include "panel.h"
#include "graphics.h"
namespace
{
	struct Singleton_WindowMgr_Members
	{
		int width, height;
		HWND hWnd;
		HINSTANCE hinstance;
		std::wstring title;
		Graphics graphics;
		std::mutex m_mutex;
		Singleton_WindowMgr_Members();
		bool initWindow();

	};
}

Singleton_WindowMgr_Members::Singleton_WindowMgr_Members() : width(0), height(0), 
															 hWnd(0), title(L"Main Window"), 
															 hinstance(nullptr) {}
typedef SingletonBase<Singleton_WindowMgr_Members> Singleton;
DECLARE_SINGLETON_STATICS(Singleton);

bool Singleton_WindowMgr_Members::initWindow() {
	RECT r = { CW_USEDEFAULT, CW_USEDEFAULT , CW_USEDEFAULT, CW_USEDEFAULT };
	if (width != 0) {
		r.right = width;
	}
	if (height != 0) {
		r.bottom = height;
	}
	if (hinstance == nullptr) {
		hinstance = GetModuleHandle(nullptr);
	}

	Panel::makeWindow(hinstance, title.c_str(), r, hWnd);
	if (!hWnd) {
		return false;
	}
	
	bool result =  graphics.init(hWnd);
	if (!result) {
		return false;
	}

	return true;
}

void WindowMgr::ellipse(float x, float y, float width, float height) {
	auto& instance = Singleton::get();
	instance.graphics.drawElipse(x, y, width, height);
}

void WindowMgr::setColor(float r, float g, float b) {
	auto& instance = Singleton::get();
	instance.graphics.setColor(r, g, b);
}

void WindowMgr::clear(float r, float g, float b) {
	auto& instance = Singleton::get();
	instance.graphics.clear(r, g, b);
}

void WindowMgr::draw(Draw_Callback* pCallback) {
	auto& instance = Singleton::get();
	instance.graphics.draw(pCallback);
}

void WindowMgr::setSize(int width, int height) {
	auto& instance = Singleton::get();
	auto lck(instance.getLock());
	instance.width = width;
	instance.height = height;
}

void WindowMgr::setTitle(wchar_t* title) {
	auto& instance = Singleton::get();
	auto lck(instance.getLock());
}

int WindowMgr::getWidth() {
	auto& instance = Singleton::get();
	auto lck(instance.getLock());
	return instance.width;
}
int WindowMgr::getHeight() {
	auto& instance = Singleton::get();
	auto lck(instance.getLock());
	return instance.height;
}

void WindowMgr::setHinstance(HINSTANCE hinst) {
	auto& instance = Singleton::get();
	auto lck(instance.getLock());
	instance.hinstance = hinst;
}

bool WindowMgr::initWindow() {
	auto& instance = Singleton::get();
	auto lck(instance.getLock());
	return instance.initWindow();
}

HWND WindowMgr::getHwnd() {
	auto& instance = Singleton::get();
	auto lck(instance.getLock());
	return instance.hWnd;
}