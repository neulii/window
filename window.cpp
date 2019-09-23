#include "window.h"
#include <iostream>


Window::Window(const wxString& title) : wxFrame(NULL,wxID_ANY, title, wxDefaultPosition,wxSize(250,150))
{
	wxPanel *panel = new wxPanel(this, wxID_ANY);
	button = new wxButton(panel, wxID_EXIT, wxT("Quit"), wxPoint(20, 20));
	button2 = new wxButton(panel,ID_MESSAGE_BUTTON,wxT("Message"),wxPoint(20,60));

	
	
	
	//connet first button with event	
	Connect(wxID_EXIT, 
			wxEVT_COMMAND_BUTTON_CLICKED, 
			wxCommandEventHandler(Window::OnQuit));

	//connect second button with event
	Connect(ID_MESSAGE_BUTTON,
			wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(Window::OnMessageButton));

	button->SetFocus();

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
}
