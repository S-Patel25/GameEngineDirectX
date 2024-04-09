#include "AppWindow.h"

struct vec3
{
	float x, y, z;
};

struct vertex
{
	vec3 position;
};


AppWindow::AppWindow()
{
}


AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();
	GraphicsEngine::get()->init();
	m_swap_chain = GraphicsEngine::get()->createSwapChain();

	RECT rc = this->getClientWindowRect();
	m_swap_chain->init(this->m_hwnd, rc.right - rc.left, rc.bottom - rc.top); //init swap chain otherwise read access vio and nullptr error occurs

	vertex list[] =
	{
		//XYZ COORDS FOR DRAWING TRIANGLE BASED ON SCREEN SPACE
		{ -0.5f, -0.5f, 0.0f }, //POS1
		{ 0.0f, 0.5f, 0.0f }, //POS2
		{ 0.5f, -0.5f, 0.0f } //POS3
	};

	m_vb = GraphicsEngine::get()->createVertexBuffer();
	UINT size_list = ARRAYSIZE(list);

	GraphicsEngine::get()->createShaders();

	void* shader_byte_code = nullptr;
	UINT size_shader = 0;
	
	GraphicsEngine::get()->getShaderBufferAndSize(&shader_byte_code, &size_shader);



	m_vb->load(list, sizeof(vertex), size_list, shader_byte_code, size_shader);
}

void AppWindow::onUpdate()
{
	Window::onUpdate();
	GraphicsEngine::get()->getImmediateDeviceContext()->clearRenderTargetColor(this->m_swap_chain,
		0, 1, 0, 1);
	
	RECT rc = this->getClientWindowRect();

	GraphicsEngine::get()->getImmediateDeviceContext()->setViewportSize(rc.right - rc.left, rc.bottom - rc.top);
	GraphicsEngine::get()->setShaders();

	GraphicsEngine::get()->getImmediateDeviceContext()->setVertexBuffer(m_vb);
	GraphicsEngine::get()->getImmediateDeviceContext()->drawTriangleList(m_vb->getSizeVertexList(), 0);


	m_swap_chain->present(true);
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	
	m_vb->release();
	m_swap_chain->release();
	GraphicsEngine::get()->release();
}