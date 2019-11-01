#ifndef _MAINMODULE_H_
#define _MAINMODULE_H_

void WINAPI Size(int width, int height);
void WINAPI RunLoop();
void WINAPI NoStroke();
void WINAPI Stroke(float r, float g, float b);
void WINAPI Ellipse(float x, float y, float width, float height);
void WINAPI Circle(float x, float y, float extent);
void WINAPI Fill(float r, float g, float b);
void WINAPI Background(float r, float g, float b);
void WINAPI Rect(float x, float y, float width, float height);
void WINAPI Square(float x, float y, float extent);
void WINAPI Line(float x1, float y1, float x2, float y2);
void WINAPI Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
void WINAPI Quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
int WINAPI Width();
int WINAPI Height();
void WINAPI NoFill();
#endif // _MAINMODULE_H_
