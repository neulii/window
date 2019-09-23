#include <wx/wx.h>

const int ID_MESSAGE_BUTTON = 100;

class Window : public wxFrame
{

private: 
	wxButton *button = nullptr;
	wxButton *button2 = nullptr;
public:

	Window(const wxString& title);
	void OnMessageButton(wxCommandEvent& event);
	void OnQuit(wxCommandEvent & event);
};

