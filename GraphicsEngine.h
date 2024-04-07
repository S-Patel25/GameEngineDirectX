#pragma once
#include <d3d11.h>

class SwapChain;
class DeviceContext;

class GraphicsEngine
{
public:

	GraphicsEngine();
	
	bool init(); //Initialize the GraphicsEngine and DirectX 11 Device

	bool release(); //Release all the resources loaded

	~GraphicsEngine();
public:

	SwapChain* createSwapChain();
	DeviceContext* getImmediateDeviceContext();

	static GraphicsEngine* get();

private:

	DeviceContext* m_imm_device_context;

	ID3D11Device* m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;

	IDXGIDevice* m_dxgi_device;
	IDXGIAdapter* m_dxgi_adapter;
	IDXGIFactory* m_dxgi_factory;

private:
	friend class SwapChain;
};