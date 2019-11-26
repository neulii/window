#include <wx/wx.h>

const int ID_MESSAGE_BUTTON = 100;
const int ID_NEW_BUTTON = 200;
const int ID_TEXT_INPUT_FIELD = 300;
const int ID_PANEL = 400;

class Window : public wxFrame
{

private: 
	wxButton *button = nullptr;
	wxButton *button2 = nullptr;
	wxButton *button_new = nullptr;
	wxTextCtrl* textInput = nullptr;

public:

	Window(const wxString& title);
	void OnMessageButton(wxCommandEvent& event);
	void OnQuit(wxCommandEvent & event);
	void OnNewButtonPressed(wxCommandEvent& event);
	void OnKeyDown(wxKeyEvent& event);
	void OnTextEnter(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

