#ifndef _MAINMODULE_H_
#define _MAINMODULE_H_

void WINAPI Size(int width, int height);
void WINAPI RunLoop();
void WINAPI Ellipse(float x, float y, float width, float height);
void WINAPI Fill(float r, float g, float b);
void WINAPI Background(float r, float g, float b);
void WINAPI Rect(float x, float y, float width, float height);
void WINAPI Line(float x1, float y1, float x2, float y2);
void WINAPI Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
#endif // _MAINMODULE_H_
