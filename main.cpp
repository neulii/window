#include "main.h"
#include "window.h"
#include <iostream>

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	Window *myWindow = new Window(wxT("Super fenster"));
	myWindow->Show(true);
	
	return true;
}
