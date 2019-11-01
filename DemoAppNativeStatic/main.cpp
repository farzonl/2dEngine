#include <engine.h>
int w = 800, h = 600;
void WINAPI setup() {
	Size(w, h);
	Stroke(0.0f, 1.0f, 0.0f);
	NoStroke();
}

float sqX = 0, sqY = 0;
void WINAPI mousePressed(int mouseX, int mouseY) {
	sqX = static_cast<float>(mouseX);
	sqY = static_cast<float>(mouseY);
}

float cX = w/2.0f, cY = h/2.0f;
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
			if (cY < height()) {
				cY+=10;
			}
		break;
		case 'D':
			if (cX < width()) {
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
	background(0.0f, 0.5f, 0.5f);
	fill(1.0f, 0.0f, 0.0f);
	rect(100, 100, 50, 150);
	line(100, 90, 150, 90);
	line(90, 100, 90, 250);
	fill(0.0f, 0.0f, 1.0f);
	ellipse(375.0f, y, 50.0f, 50.f);
	fill(1.0f, 1.0f, 1.0f);
	triangle(30, 75, 58, 20, 86, 75);
	quad(138, 31, 186, 20, 169, 63, 130, 76);
	square(sqX, sqY, 50);
	circle(cX, cY, 25.0f);
}