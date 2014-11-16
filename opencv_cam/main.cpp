#include "opencv.h"
#include "ShowFPS.h"
#include <stdio.h>

int main(int argc, char* argv[]){
	ShowFPS showFPS;
	bool fps = false;
	printf("total:%d\n",argc-1);
	cv::VideoCapture cap[5];
	for(int i=0;i<argc-1;i++){
		printf("opening %s\n",argv[i+1]);
		cap[i].open(argv[i+1]);
		if(!cap[i].isOpened()){
			printf("Unabled. Now, trying %d\n",atoi(argv[i+1]));
			cap[i].open(atoi(argv[i+1]));
			if(!cap[i].isOpened())printf("unabled to open:%d\n",i);
		}
	}
	cv::Mat src[5];
	while(1){
		showFPS.count();
		for(int i=0; i<5; i++){
			cap[i] >> src[i];
			std::ostringstream oss;
			oss << i;
			std::string str = "original";
			str.append(oss.str());
			if(!src[i].empty()){
				if(fps)showFPS.show(src[i]);
				cv::imshow(str, src[i]);
			}
		}
		switch(cv::waitKey(20)){
		case 'f':
			if(fps)fps=false;
			else fps=true;
			break;
		case 27:
			printf("closing all.\n");
			return 0;
		}
	}

	return 0;
}