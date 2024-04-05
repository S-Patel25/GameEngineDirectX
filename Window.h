#pragma once
#include <Windows.h> //library to create window



class Window
{
public:
	Window();

	bool init(); //init window
	bool release(); //release window
	bool broadcast();
	bool isRunning();

	RECT getClientWindowRect(); //to get window size of client app
	void setHWND(HWND hwnd);

	//event stuff

	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onDestroy() = 0;

protected:
	HWND m_hwnd;
	bool m_is_run;
};

