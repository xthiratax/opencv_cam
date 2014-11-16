#include "ShowFPS.h"


ShowFPS::ShowFPS(void)
{
	this->cnt = 0;
	this->oldcnt = 0;
	this->nowTime = 0;
	this->diffTime = 0;

	this->fps = 0;
	this->f = ( 1000 / cv::getTickFrequency());

	this->startTime = cv::getTickCount();

}


ShowFPS::~ShowFPS(void)
{
}


int ShowFPS::FPS()
{
	return this->fps;
}


void ShowFPS::count(void)
{
	this->nowTime = cv::getTickCount();
	this->diffTime = (int)((this->nowTime - this->startTime) * this->f);

	if( this->diffTime >= 1000){
		this->startTime = this->nowTime;
		this->fps = this->cnt - this->oldcnt;
		this->oldcnt = this->cnt;
	}

	this->cnt++;
}

void ShowFPS::show(cv::OutputArray OUT)
{
	cv::Mat dst;

	dst = OUT.getMat();

	std::ostringstream oss;

	oss << this->fps;
	out = "fps:";
	out.append(oss.str());

	cv::putText(dst, this->out, cv::Point(2, 28), cv::FONT_HERSHEY_SIMPLEX,
		1, cv::Scalar( 255, 255, 255), 2, CV_AA);

	return;
}
