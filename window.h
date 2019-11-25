#include <wx/wx.h>

const int ID_MESSAGE_BUTTON = 100;
const int ID_NEW_BUTTON = 200;

class Window : public wxFrame
{

private: 
	wxButton *button = nullptr;
	wxButton *button2 = nullptr;
	wxButton *button_new = nullptr;

public:

	Window(const wxString& title);
	void OnMessageButton(wxCommandEvent& event);
	void OnQuit(wxCommandEvent & event);
	void OnNewButtonPressed(wxCommandEvent& event);
	void OnKeyDown(wxKeyEvent& event);
};

