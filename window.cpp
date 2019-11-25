#include "window.h"
#include <iostream>


Window::Window(const wxString& title) : wxFrame(NULL,wxID_ANY, title, wxDefaultPosition,wxSize(500,500))
{
	wxPanel *panel = new wxPanel(this, wxID_ANY);
	button = new wxButton(panel, wxID_EXIT, wxT("Quit"), wxPoint(20, 20));
	button2 = new wxButton(panel,ID_MESSAGE_BUTTON,wxT("Message"),wxPoint(20,60));
	button_new = new wxButton(panel,ID_NEW_BUTTON, wxT("Neuer Button"),wxPoint (20,100));

	
	
	
	//connet first button with event	
	Connect(wxID_EXIT, 
			wxEVT_COMMAND_BUTTON_CLICKED, 
			wxCommandEventHandler(Window::OnQuit));

	//connect second button with event
	Connect(ID_MESSAGE_BUTTON,
			wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(Window::OnMessageButton));

	button->SetFocus();

	//connect new_button with event
	Connect(ID_NEW_BUTTON, 
			wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(Window::OnNewButtonPressed));

	panel->Bind(wxEVT_CHAR_HOOK, &Window::OnKeyDown,this);

	//	Centre();
}

void Window::OnQuit(wxCommandEvent& event)
{
	 wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Error loading file"), 
					 wxT("Error"), 
					 wxOK | wxICON_ERROR);
	 dial->ShowModal();
  
  

}

void Window::OnMessageButton(wxCommandEvent& event)
{
	std::cout << "button pressed" << std::endl;
	std::cout << "super du" << std::endl;
}

void Window::OnNewButtonPressed(wxCommandEvent& event)
{
	std::cout << "new button" << std::endl;
	std::cout << WXK_ESCAPE << std::endl;

}

//if press ESC exit program
void Window::OnKeyDown(wxKeyEvent& event)
{
	if(event.GetKeyCode()==27)
		exit(0);
	event.Skip();
}

