/*
	Purpose: Manage Camera Thread & Camera Class
	
	Created: Jinfeng Zhuang, 2013.3.22
*/

#include "wx/wx.h"
#include "mainframe.h"

class CameraThread : public wxThread
{
public:
	CameraThread(CameraView * view);
	~CameraThread();
	
	virtual void *Entry();
};

class Camera
{
public:
	Camera(CameraView * view);
	~Camera();
	
	int Init();
	void Start();
	
protected:
	IplImage GetFrame();
	wxBitmap CopyFrame(IplImage &image);
	
private:
	CvCapture * m_capture;
	IplImage * m_image;
	CameraView * m_cameraview;
};