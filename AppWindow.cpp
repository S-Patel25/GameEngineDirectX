#include "AppWindow.h"

AppWindow::AppWindow()
{

}

void AppWindow::onCreate()
{
	//Window::onCreate();
	GraphicsEngine::get()->init();

	mSwapChain = GraphicsEngine::get()->createSwapChain();

	RECT rect = this->getClientWindowRect();
	mSwapChain->init(this->m_hwnd, rect.right - rect.left, rect.bottom - rect.top);;//difference between width and height
}

void AppWindow::onUpdate()
{

}

void AppWindow::onDestroy()
{
	Window::onDestroy();

	mSwapChain->release();
	GraphicsEngine::get()->release();

}