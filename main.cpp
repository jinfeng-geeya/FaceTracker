/*
	Purpose:
		The main thread, which the App(Infrastruction - message 
		loop and default message handlers) and the Frame(GUI facility
		) stacked in, is a large thread which need large memory for
		it's method stack and data storage!
		
	Created: Jinfeng Zhuang, 2013.3.22
*/
#include "wx/wx.h"
#include "mainframe.h"

class App : public wxApp
{
public:
	bool OnInit();
};

IMPLEMENT_APP(App);

bool App::OnInit()
{
	/* Construct This application's Infrastruction */
	// 1. GUI
	MainFrame * frame = new MainFrame(wxSize(600, 400));
	// 2. Camera Thread
	CameraThread * thread = new CameraThead(frame->m_cameraview);
	
	/* As resources has prepared, now startup them */
	// 1. GUI showing for User
	SetTopWindow(frame);
	frame->Show();
	// 2. Camera thread start capture frames
	if(wxTHREAD_NO_ERROR != thread->Create())
		wxExit();
	if(wxTHREAD_NO_ERROR != thread->Run())
		wxExit();
		
	/* Init work has done! System is Running! */
	return true;
}
