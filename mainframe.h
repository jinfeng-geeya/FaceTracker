/*
	Purpose: MainFrame Class Declaration
	
	Created: Jinfeng Zhuang, 2013.3.22
*/

#include "wx/wx.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxSize &size);
	
	void CreateClient();
	
protected:
	DECLARE_EVENT_TABLE();
};

class CameraView : public wxWindow
{
public:
	CameraView(wxWindow &parent, const wxSize &size);
	
	void OnPaint(wxPaintEvent &event);
	
	void NewFrame(const wxBitmap &frame);
	
private:
	wxBitmap m_frame;
	
protected:
	DECLARE_EVENT_TABLE();
};