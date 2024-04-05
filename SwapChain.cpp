#include "SwapChain.h"
#include "GraphicsEngine.h"

SwapChain::SwapChain()
{

}


bool SwapChain::init(HWND hwnd, UINT width, UINT height)
{
    ID3D11Device* device = GraphicsEngine::get()->mD3dDevice;

    //SETTING PROPERTIES OF THE SWAP CHAIN

    //SWAP CHAIN is using back and front buffer to handle rendering (renders are drawn in back buffer then once done displayed on front buffer to avoid screen tearing partial frames and has smooth anims)
    DXGI_SWAP_CHAIN_DESC desc;
    ZeroMemory(&desc, sizeof(desc)); //makes all values using this mem zero
    desc.BufferCount = 1;
    desc.BufferDesc.Width = width;
    desc.BufferDesc.Height = height;
    desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; //rgb and alpha 8 pixels
    desc.BufferDesc.RefreshRate.Numerator = 60; //60hz
    desc.BufferDesc.RefreshRate.Denominator = 1;
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; //treat as render targets
    desc.OutputWindow = hwnd; //handle window (screen)
    desc.SampleDesc.Quality = 0;
    desc.Windowed = TRUE;


    //make the swap chain based on hwnd param
    HRESULT hr = GraphicsEngine::get()->mDxgiFactory->CreateSwapChain(device, &desc, &mSwapChain);

    if (FAILED(hr))
    {
        return false;
    }

    if (SUCCEEDED(hr))
    {

    }

    return true;
}

bool SwapChain::release()
{
    mSwapChain->Release(); //release swap chain instance
    delete this; //deletes instance of swap chain

    return true;
}
