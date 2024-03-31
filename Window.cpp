#include "Window.h"

//Window* window = nullptr;


Window::Window()
{

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) //event handling and callbacks
{
    switch (msg)
    {
    case WM_CREATE:
    {
        // event fired when the window is created
        // collected here..
        Window* window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
        // and then stored for later lookup
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
        window->onCreate();
        break;
    }
    case WM_DESTROY:
    {
        // Event fired when the window is destroyed
        Window* window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
        window->onDestroy();
        ::PostQuitMessage(0);
        break;
    }
    default:
        return::DefWindowProc(hwnd, msg, wparam, lparam); 
    }

    return NULL;


}

bool Window::init()
{
    WNDCLASSEX wc; //windown api class

    //setting attributes for the window
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    wc.lpszClassName = L"MyWindowClass";
    wc.lpszMenuName = L"";
    wc.style = NULL;
    wc.lpfnWndProc = &WndProc;


    if (!::RegisterClassEx(&wc)) //if class doesn't register correctly (essentially a null pointer check)
    {
        return false;
    }

    m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindowClass", L"DirectX Application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
        NULL, NULL, NULL, this); //create window based on params

    if (!m_hwnd) //null pointer check
    {
        return false;
    }

    //show window
    ::ShowWindow(m_hwnd, SW_SHOW);
    ::UpdateWindow(m_hwnd);
   

    //flag for if window is running
    m_is_run = true;
    return true;
}

bool Window::release()
{
    //destroy the window
    if (!::DestroyWindow(m_hwnd))
    {
        return false;
    }


    return true;
}

bool Window::broadcast()
{
    MSG msg;

    while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) < 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    this->onUpdate();

    Sleep(0); //optimize a bit

    return true;
}

bool Window::isRunning()
{
    return m_is_run;
}

void Window::onDestroy()
{
    m_is_run = false;
}