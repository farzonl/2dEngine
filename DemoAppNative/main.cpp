#include "..\2DEngine\pch.h"
#include "..\2DEngine\MainModule.h"
#include "..\2DEngine\ManagedLayer.h"

void WINAPI setup() {
	Size(800, 600);
	Fill(1.0f, 1.0f, 1.0f);
}

float y = 0, ySpeed = 0;

void WINAPI draw() {
	ySpeed += 1.0f;
	y += ySpeed;
	if (y > 600) {
		y = 600;
		ySpeed = -30.0f;
	}
	Background(0.0f, 0.0f, 0.5f);
	Ellipse(375.0f, y, 50.0f, 50.f);
}

int main() {
	Setup_SetCallback(setup);
	Draw_SetCallback(draw);

	RunLoop();
}