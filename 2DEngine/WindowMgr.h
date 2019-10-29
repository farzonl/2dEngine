#ifndef Window_MGR_H
#define Window_MGR_H

#include "ManagedLayer.h"

class WindowMgr
{
public:
	static void setSize(int width, int height);
	static void setTitle(wchar_t* title);
	static int getWidth();
	static int getHeight();
	static HWND getHwnd();
	static void setHinstance(HINSTANCE hinst);
	static bool initWindow();
	static void draw(Draw_Callback* pCallback);
	// note make these draw functions nonblocking
	static void ellipse(float x, float y, float width, float height); 
	static void setColor(float r, float g, float b);
	static void clear(float r, float g, float b);
private:
	WindowMgr() = delete;
};
#endif //Window_MGR_H
