#ifndef __Engine_H__
#define __Engine_H__

#include "..\pch.h"
#include "..\MainModule.h"
#include "..\ManagedLayer.h"

#define sq(a) pow(a,2)
#define random(low, high) rand() % high + low
#define size Size
#define noFill NoFill
#define stroke Stroke
#define noStroke NoStroke
#define background Background
#define fill Fill
#define rect Rect 
#define line Line 
#define ellipse Ellipse
#define triangle Triangle
#define quad Quad 
#define square Square
#define circle Circle
#define height Height
#define width Width

typedef int color;
typedef bool boolean;
typedef bool Boolean;
typedef std::string String;

#undef  Size
#undef  Stroke
#undef  NoStroke
#undef  Background
#undef  Fill
#undef  Rect 
#undef  Line 
#undef  Ellipse
#undef  Triangle
#undef  Quad 
#undef  Square
#undef  Circle
#undef  Height
#undef  Width

extern Draw_Callback draw;
extern Setup_Callback setup;
extern MousePressed_Callback mousePressed;
extern KeyPressed_Callback keyPressed;

template<typename  T>
void matDel(T**  arr, int COL);
void println(std::string str...);
void println(const char* fmt...);

template<typename  T>
T** matAlloc(int COLS, int ROWS) {
	T** arr = new T* [COLS];
	for (int i = 0; i < COLS; ++i) {
		arr[i] = new T[ROWS];
		memset(arr[i], 0, ROWS*sizeof(T));
	}
	return arr;
}

template<typename  T>
void matDel(T** arr, int COLS) {
	if (arr) {
		for (int i = 0; i < COLS; ++i) {
			if (arr[i]) {
				delete[] arr[i];
				arr[i] = nullptr;
			}
		}
		delete[] arr;
		arr = nullptr;
	}
}

inline std::string const boolToString(bool b)
{
	return b ? "true" : "false";
}

template<typename  T>
void matSwap(T** arr1, T** arr2, int COLS) {
	if (arr1 != nullptr && arr2 != nullptr) {
		for (int i = 0; i < COLS; ++i) {
			std::swap(arr1[i], arr2[i]);
		}
	}
}
void println(std::string& str...) {
	const char* fmt = str.c_str();
	println(fmt);
}
void println(const char* fmt...) {
	va_list args;
	va_start(args, fmt);

	while (*fmt != '\0') {
		if (*fmt == 'd') {
			int i = va_arg(args, int);
			std::cout << i << '\n';
		}
		else if (*fmt == 'c') {
			// note automatic conversion to integral type
			int c = va_arg(args, int);
			std::cout << static_cast<char>(c) << '\n';
		}
		else if (*fmt == 'f') {
			double d = va_arg(args, double);
			std::cout << d << '\n';
		}
		++fmt;
	}

	va_end(args);
}

float map(float value, float start1, float stop1, float start2, float stop2) {
	//TODO
	return 0;
}

int main() {
	Setup_SetCallback(setup);
	Draw_SetCallback(draw);
	MousePressed_SetCallback(mousePressed);
	KeyPressed_SetCallback(keyPressed);
	RunLoop();
}

#endif // __Engine_H__