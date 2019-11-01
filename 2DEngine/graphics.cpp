#include "pch.h"
#include "graphics.h"


Graphics::Graphics() : factory(nullptr),
					   renderTarget(nullptr), 
					   brush(nullptr),
					   height(0), 
					   width(0),
					   bStroke(true),
					   bFill(true),
					   strokeWeight(3.0f) {}

Graphics::~Graphics() {
	if (factory) {
		factory->Release();
	}
	if (renderTarget) {
		renderTarget->Release();
	}
	if (brush) {
		brush->Release();
	}
	if (strokeBrush) {
		strokeBrush->Release();
	}
}
int Graphics::getHeight() {
	return height;
}

int Graphics::getWidth() {
	return width;
}
bool Graphics::init(HWND hwnd) {
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE::D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (hr != S_OK) {
		return false;
	}
	RECT rect;
	GetClientRect(hwnd, &rect);
	this->width = rect.right;
	this->height = rect.bottom;
	hr = factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
										D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(rect.right, rect.bottom)),
										&renderTarget);
	if (hr != S_OK) {
		return false;
	}

	hr = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0), &brush);

	if (hr != S_OK) {
		return false;
	}

	hr = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0), &strokeBrush);

	if (hr != S_OK) {
		return false;
	}

	return true;
}

void Graphics::clear(float r, float g, float b) {
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::setColor(float r, float g, float b) {
	bFill = true;
	brush->SetColor(D2D1::ColorF(r, g, b));
}

void Graphics::noStroke() {
	bStroke = false;
}
void Graphics::noFill() {
	bFill = false;
}

void Graphics::stroke(float r, float g, float b) {
	bStroke = true;
	strokeBrush->SetColor(D2D1::ColorF(r, g, b));
}

void Graphics::drawElipse(float x, float y, float width, float height) {
	auto elipse = D2D1::Ellipse(D2D1::Point2F(x, y), width, height);
	if (bStroke) {
		renderTarget->DrawEllipse(elipse, strokeBrush, strokeWeight);
	}
	if (bFill) {
		renderTarget->FillEllipse(elipse, brush);
	}
}

void Graphics::drawRect(float x, float y, float width, float height) {
	auto rect = D2D1::RectF(x, y, x + width, y + height);
	if (bStroke) {
		renderTarget->DrawRectangle(rect, strokeBrush, strokeWeight);
	}
	if (bFill) {
		renderTarget->FillRectangle(rect, brush);
	}
}

void Graphics::drawLine(float x1, float y1, float x2, float y2) {
	renderTarget->DrawLine(D2D1::Point2F(x1, y1), D2D1::Point2F(x2, y2), strokeBrush, strokeWeight);
}

void Graphics::drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
	renderTarget->DrawLine(D2D1::Point2F(x1, y1), D2D1::Point2F(x2, y2), strokeBrush, strokeWeight);
	renderTarget->DrawLine(D2D1::Point2F(x2, y2), D2D1::Point2F(x3, y3), strokeBrush, strokeWeight);
	renderTarget->DrawLine(D2D1::Point2F(x3, y3), D2D1::Point2F(x1, y1), strokeBrush, strokeWeight);
}

void Graphics::drawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	renderTarget->DrawLine(D2D1::Point2F(x1, y1), D2D1::Point2F(x2, y2), strokeBrush, strokeWeight);
	renderTarget->DrawLine(D2D1::Point2F(x2, y2), D2D1::Point2F(x3, y3), strokeBrush, strokeWeight);
	renderTarget->DrawLine(D2D1::Point2F(x3, y3), D2D1::Point2F(x4, y4), strokeBrush, strokeWeight);
	renderTarget->DrawLine(D2D1::Point2F(x4, y4), D2D1::Point2F(x1, y1), strokeBrush, strokeWeight);
}