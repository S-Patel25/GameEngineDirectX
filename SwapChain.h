#pragma once
#include <d3d11.h>

class DeviceContext;
class SwapChain
{
public:
	SwapChain();
	
	bool init(HWND hwnd, UINT width, UINT height); //Initialize SwapChain for a window


	bool present(bool vsync);

	
	bool release(); //Release the swap chain
	~SwapChain();

private:
	IDXGISwapChain* m_swap_chain;
	ID3D11RenderTargetView* m_rtv;
	ID3D11DepthStencilView* m_dsv;

	friend class DeviceContext;
};