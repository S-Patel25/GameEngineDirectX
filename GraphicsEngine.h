#pragma once
#include <d3d11.h> //directx library
#include "SwapChain.h"

class SwapChain;

class GraphicsEngine
{

public:
	GraphicsEngine();

	//intialize the engine and DirectX dev
	bool init();

	//release all resources loaded
	bool release();

	static GraphicsEngine* get();

	SwapChain* createSwapChain();

private:
	ID3D11Device* mD3dDevice;
	D3D_FEATURE_LEVEL mFeatureLevel;
	ID3D11DeviceContext* mImmContext;

	IDXGIDevice* mDxgiDevice;
	IDXGIAdapter* mDxgiAdapter;
	IDXGIFactory* mDxgiFactory;

	friend class SwapChain; //make a friend class to allow for use
};

