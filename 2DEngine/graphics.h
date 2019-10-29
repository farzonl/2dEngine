#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <Windows.h>
#include <d2d1.h>

class Graphics {
	private:
		ID2D1Factory* factory;
		ID2D1HwndRenderTarget* renderTarget;
		ID2D1SolidColorBrush* brush;
		int height, width;
	public:
		Graphics();
		~Graphics();
		int getHeight();
		int getWidth();
		bool init(HWND hwnd);
		template<typename Functor>
		void draw(Functor f) {
			renderTarget->BeginDraw();
			f();
			renderTarget->EndDraw();
		}
		void clear(float r,float g, float b);
		void setColor(float r, float g, float b);
		void drawElipse(float x, float y, float width, float height);
};

#endif // __GRAPHICS_H__