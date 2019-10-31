#include "..\2DEngine\pch.h"
#include "..\2DEngine\MainModule.h"
#include "..\2DEngine\ManagedLayer.h"
int width = 800;
int height = 600;
void WINAPI setup() {
	Size(width, height);
	Stroke(0.0f, 1.0f, 0.0f);
	NoStroke();
}

float sqX = 0, sqY = 0;
void WINAPI mousePressed(int mouseX, int mouseY) {
	sqX = static_cast<float>(mouseX);
	sqY = static_cast<float>(mouseY);
}

float cX = width/2.0f, cY = height/2.0f;
void WINAPI keyPressed(char key) {
	switch (key) {
		case 'W':
			if (cY > 0) {
				cY-=10;
			}
		break;
		case 'A':
			if (cX > 0) {
				cX-=10;
			}
		break;
		case 'S':
			if (cY < height) {
				cY+=10;
			}
		break;
		case 'D':
			if (cX < width) {
				cX+=10;
			}
		break;
	}
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
	Line(100, 90, 150, 90);
	Line(90, 100, 90, 250);
	Fill(0.0f, 0.0f, 1.0f);
	Ellipse(375.0f, y, 50.0f, 50.f);
	Fill(1.0f, 1.0f, 1.0f);
	Triangle(30, 75, 58, 20, 86, 75);
	Quad(138, 31, 186, 20, 169, 63, 130, 76);
	Square(sqX, sqY, 50);
	Circle(cX, cY, 25.0f);
}

int main() {
	Setup_SetCallback(setup);
	Draw_SetCallback(draw);
	MousePressed_SetCallback(mousePressed);
	KeyPressed_SetCallback(keyPressed);
	RunLoop();
}