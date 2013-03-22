/*
	Note:
	
	Created: Jinfeng Zhuang, 2013.3.22
*/

#include "mainframe.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxSize &size)
	: wxFrame(	NULL, wxID_ANY, wxEmptyString
				,wxPoint(100,100), wxSize(600,400))
{
	SetBackgroundColour(wxLIGHT_GREY);
	
	CreateClient();
}

void MainFrame::CreateClient()
{
	wxPanel * panel = new wxPanel(	this, wxID_ANY, wxDefaultPosition
									,wxSize(400,400));
	panel->SetBackgroundColour(wxColor(0,80,60));
	
	CameraView * view = new CameraView(panel, wxSize(200,200));
}

BEGIN_EVENT_TABLE(CameraView, wxWindow)
	wxPAINT(CameraView::OnPaint)
END_EVENT_TABLE()

CameraView::CameraView(wxWindow &parent, const wxSize &size)
	: wxWindow(parent, wxID_ANY, wxDefaultPosition, size)
{
	SetBackgroundColour(wxBLACK);
}

void CameraView::NewFrame(const wxBitmap &frame)
{
	m_frame = frame;
	Update();
}

void CameraView::OnPaint(wxPaintEvent &event)
{
	wxPaintDC dc(this);
	
	dc.DrawBitmap(m_frame);
}