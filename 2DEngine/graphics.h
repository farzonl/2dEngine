#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <d2d1.h>

class Graphics {
	private:
		ID2D1Factory* factory;
		ID2D1HwndRenderTarget* renderTarget;
		ID2D1SolidColorBrush* brush;
		ID2D1SolidColorBrush* strokeBrush;
		int height, width;
		bool bStroke, bFill;
		float strokeWeight;
	public:
		Graphics();
		~Graphics();
		int getHeight();
		int getWidth();
		void noStroke();
		void noFill();
		void stroke(float r, float g, float b);
		bool init(HWND hwnd);
		template<typename Functor>
		void draw(Functor f) {
			renderTarget->BeginDraw();
			f();
			renderTarget->EndDraw();
		}
		void rotate(float degrees);
		void clear(float r,float g, float b);
		void setColor(float r, float g, float b);
		void drawElipse(float x, float y, float width, float height);
		void drawRect(float x, float y, float width, float height);
		void drawLine(float x1, float y1, float x2, float y2);
		void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
		void drawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

};

#endif // __GRAPHICS_H__