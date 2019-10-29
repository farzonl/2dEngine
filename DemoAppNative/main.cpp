#include "..\2DEngine\pch.h"
#include "..\2DEngine\MainModule.h"
#include "..\2DEngine\ManagedLayer.h"

void WINAPI setup() {
	Size(800, 600);
}

float y = 0, ySpeed = 0;

void WINAPI draw() {
	ySpeed += 1.0f;
	y += ySpeed;
	if (y > 600) {
		y = 600;
		ySpeed = -30.0f;
	}
	Background(0.0f, 0.5f, 0.5f);
	Fill(1.0f, 0.0f, 0.0f);
	Rect(100, 100, 50, 150);
	Fill(0.0f, 1.0f, 0.0f);
	Line(100, 90, 150, 90);
	Line(90, 100, 90, 250);
	Fill(0.0f, 0.0f, 1.0f);
	Ellipse(375.0f, y, 50.0f, 50.f);
	Fill(1.0f, 1.0f, 1.0f);
	Triangle(30, 75, 58, 20, 86, 75);
	Quad(138, 31, 186, 20, 169, 63, 130, 76);
}

int main() {
	Setup_SetCallback(setup);
	Draw_SetCallback(draw);

	RunLoop();
}