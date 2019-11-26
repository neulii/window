#include "window.h"
#include <iostream>

		
wxBEGIN_EVENT_TABLE(Window, wxFrame)
    EVT_BUTTON(ID_MESSAGE_BUTTON, Window::OnMessageButton)
	EVT_BUTTON(ID_NEW_BUTTON, Window::OnNewButtonPressed)
	EVT_BUTTON(wxID_EXIT, Window::OnQuit)
	EVT_CHAR_HOOK(Window::OnKeyDown)	
	EVT_TEXT_ENTER(ID_TEXT_INPUT_FIELD, Window::OnTextEnter)
wxEND_EVENT_TABLE()


Window::Window(const wxString& title) : wxFrame(NULL,wxID_ANY, title, wxDefaultPosition,wxSize(500,500))
{
	wxPanel *panel = new wxPanel(this, ID_PANEL);
	button = new wxButton(panel, wxID_EXIT, wxT("Quit"), wxPoint(20, 20));
	button2 = new wxButton(panel,ID_MESSAGE_BUTTON,wxT("Message"),wxPoint(20,60));
	button_new = new wxButton(panel,ID_NEW_BUTTON, wxT("Neuer Button"),wxPoint (20,100));
	
 	textInput = new wxTextCtrl( panel, ID_TEXT_INPUT_FIELD, "", 
		wxPoint(20,200), wxSize(200,30), wxTE_PROCESS_ENTER);
    
	textInput->SetHint("Don't use 12345 here");

		Centre();
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

	/*if(event.GetKeyCode()==(int)WXK_RETURN)
	{
		std::cout << "enter" << std::endl;
	}
	*/
	event.Skip();
}

void Window::OnTextEnter(wxCommandEvent& event)
{
	//std::cout << "enter in textfield" << std::endl;
	if(textInput->GetValue()!="")
		std::cout << textInput->GetValue() << std::endl;

}
