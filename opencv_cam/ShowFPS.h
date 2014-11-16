#pragma once
#include "opencv.h"
#include <opencv2/opencv.hpp>

class ShowFPS
{
private:
	int cnt;
	int oldcnt;
	int64 nowTime;
	int64 diffTime;
	int64 startTime;

	int fps;
	double f;

	cv::VideoCapture cap;

	std::string out;

public:
	ShowFPS(void);
	~ShowFPS(void);
	int FPS();
	void count(void);
	void show(cv::OutputArray);
};

