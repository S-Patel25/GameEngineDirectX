#pragma once
#include <d3d11.h> //directx library

class GraphicsEngine
{

public:
	GraphicsEngine();

	//intialize the engine and DirectX dev
	bool init();

	//release all resources loaded
	bool release();

	static GraphicsEngine* get();

private:
	ID3D11Device* mD3dDevice;
	D3D_FEATURE_LEVEL mFeatureLevel;
	ID3D11DeviceContext* mImmContext;
};

