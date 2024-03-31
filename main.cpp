#include "AppWindow.h"





int main()
{
	AppWindow app;

	if (app.init())
	{
		while (app.isRunning()) //test window
		{
			app.broadcast();
		}
	}

	return 0;
}