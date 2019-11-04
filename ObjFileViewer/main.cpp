#include <engine.h>
#include "model.h"
#include "geometry.h"

int w = 800, h = 800;
Model headModel("obj\\african_head.obj");
Model poseModel("obj\\diablo3_pose.obj");
Model* model = nullptr;
void WINAPI setup() {
	Size(w, h);
	Stroke(1.0f, 1.0f, 1.0f);
	model = &poseModel;
	
}

void WINAPI mousePressed(int mouseX, int mouseY) {

}


void WINAPI keyPressed(char key) {
	switch (key) {
	case '1':
		model = &poseModel;
		break;
	case '2':
		model = &headModel;
		break;
	}
}

void WINAPI draw() {
	background(0.0f, 0.0f, 0.0f);
	rotate(180);
	for (int i = 0; i < model->nfaces(); i++) {
		std::vector<int> face = model->face(i);
		for (int j = 0; j < 3; j++) {
			Vec3f v0 = model->vert(face[j]);
			Vec3f v1 = model->vert(face[(j + 1) % 3]);
			int x0 = (v0.x + 1.) * width() / 2.;
			int y0 = (v0.y + 1.) * height() / 2.;
			int x1 = (v1.x + 1.) * width() / 2.;
			int y1 = (v1.y + 1.) * height() / 2.;
			line(x0, y0, x1, y1);
		}
	}
}