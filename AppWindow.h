#pragma once

#include "Window.h"


class AppWindow : public Window
{
public:
	AppWindow();



	// Inherited via Window
	virtual void onCreate() override; //override from window class
	virtual void onUpdate() override;
	virtual void onDestroy() override;

};
