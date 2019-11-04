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
	static void line(float x1, float y1, float x2, float y2);
	static void rect(float x, float y, float width, float height);
	static void triangle(float x1, float y1, float x2, float y2, float x3, float y3);
	static void setColor(float r, float g, float b);
	static void clear(float r, float g, float b);
	static void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	static void noStroke();
	static void stroke(float r, float g, float b);
	static void noFill();
	static void rotate(float degrees);
private:
	WindowMgr() = delete;
};
#endif //Window_MGR_H
