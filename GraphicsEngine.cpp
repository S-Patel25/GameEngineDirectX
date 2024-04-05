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

    for (UINT driverIndex = 0; driverIndex < numDriverTypes;) //loop through direct x driver types
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



    return true;
}

bool GraphicsEngine::release()
{
    mImmContext->Release();
    mD3dDevice->Release(); //release resources used

    return true;
}

GraphicsEngine* GraphicsEngine::get()
{
    static GraphicsEngine engine; //since its static, will only be created once when ran
    return &engine;
}
