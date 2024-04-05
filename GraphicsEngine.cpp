#include "GraphicsEngine.h"



GraphicsEngine::GraphicsEngine()
{

}
bool GraphicsEngine::init()
{

    //INTIAIZLED DIRECTX API
    D3D_DRIVER_TYPE driverTypes[] =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE
    };

    UINT numDriverTypes = ARRAYSIZE(driverTypes);

    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0 //feauture level of directx
    };

    UINT numFeatureLevels = ARRAYSIZE(featureLevels);

    HRESULT res = 0;

    for (UINT driverIndex = 0; driverIndex < numDriverTypes;) //loop through direct x driver types till finds succesful one
    {
         res = D3D11CreateDevice(NULL, driverTypes[driverIndex], NULL, NULL, 
            featureLevels, numFeatureLevels,
            D3D11_SDK_VERSION, 
            &mD3dDevice, &mFeatureLevel, &mImmContext); //creates the directx device

        if (SUCCEEDED(res))
        {
            break; //successfully creates device
        }

        ++driverIndex; //for better performance
    }

    if (FAILED(res))
    {
        return false;
    }

    mD3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&mDxgiDevice);
    mDxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&mDxgiAdapter);
    mDxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&mDxgiFactory);

    return true;
}

bool GraphicsEngine::release()
{
    mDxgiDevice->Release();
    mDxgiAdapter->Release();
    mDxgiFactory->Release();

    mImmContext->Release();
    mD3dDevice->Release(); //release resources used



    return true;
}

GraphicsEngine* GraphicsEngine::get()
{
    static GraphicsEngine engine; //since its static, will only be created once when ran
    return &engine;
}

SwapChain* GraphicsEngine::createSwapChain()
{
    return new SwapChain();
}
