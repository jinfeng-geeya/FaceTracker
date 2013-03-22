/*
	Purpose: Manage Camera Thread & Camera Class
	
	Created: Jinfeng Zhuang, 2013.3.22
*/

#include "camera.h"
#include "cv/cv.h"

CameraThread::CameraThread(CameraView * view)
	: wxThread(wxDETACHED)
{
	Camera * camera = new Camera(view);
}

CameraThread::~CameraThread()
{}

virtual void *Entry()
{
	if(false == camera->Init())
		wxExit();
		
	camera->Start();	// run into loop
}

Camera::Camera(CameraView * view)
{
	m_cameraview = view;
}

Camera::~Camera()
{}

int Camera::Init()
{
	CvCapture * capture = cvCaptureFromCAM(-1);
}

void Camera::Start()
{
	while(1)
	{
		m_image = cvQueryFrame(m_capture);
		if(!m_image) continue;
		
	}
}