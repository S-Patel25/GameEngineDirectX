#pragma once
#include <Windows.h>



class Window
{
public:
	Window();
	
	bool init(); //Initialize the window
	bool broadcast();
	
	bool release(); //show up the window
	bool isRun();

	RECT getClientWindowRect();
	void setHWND(HWND hwnd);


	//EVENTS
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();


	~Window();
protected:

	HWND m_hwnd;
	bool m_is_run;
};