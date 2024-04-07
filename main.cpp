#include "AppWindow.h"





int main()
{
	AppWindow app;

	if (app.init())
	{
		while (app.isRun()) //test window
		{
			app.broadcast();
		}
	}

	return 0;
}