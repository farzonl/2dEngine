#ifndef __PANEL_H__
#define __PANEL_H__

class Panel {
public:
	static bool makeWindow(HINSTANCE hinstance, LPCWSTR windowName, RECT& r, HWND& hwnd);
private:
	Panel() = delete;
};

#endif //__PANEL_H__