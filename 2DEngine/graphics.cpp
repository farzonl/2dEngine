#include "pch.h"
#include "graphics.h"


Graphics::Graphics() : factory(nullptr),
					   renderTarget(nullptr), 
					   brush(nullptr),
					   height(0), 
					   width(0) {}

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

	return true;
}

void Graphics::clear(float r, float g, float b) {
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::setColor(float r, float g, float b) {
	brush->SetColor(D2D1::ColorF(r, g, b));
}

void Graphics::drawElipse(float x, float y, float width, float height) {
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), width, height), brush, 3.0f);
}