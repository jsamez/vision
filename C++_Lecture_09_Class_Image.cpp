#include <iostream>
#include <string>
#include "ColorDefine.h"

class DrawCanvas
{
private:
	cv::Mat canvas;
	uchar* pCanvas=nullptr;
public:
	DrawCanvas();
	DrawCanvas(int rows, int cols, int channels=1)
	{
		if(channels==1)
			canvas = cv::Mat::zeros(rows, cols, CV_8UC1);
		else if (channels == 3)
			canvas = cv::Mat::zeros(rows, cols, CV_8UC3);
		pCanvas = canvas.data;
	}
	~DrawCanvas() {}

	const cv::Mat& GetCanvas() {return canvas;}
	void Draw_line(cv::Point pt1, cv::Point pt2, cv::Scalar color=255)
	{
	
	}
	void Draw_circle(cv::Point pt, int radius, cv::Scalar color=255)
	{
		const double PI = 3.14159265358979323846;
		// ���� �ܰ��� �׸��� ���� ���� ����
		int points = 360*3; // 1�� ������ �׸���
		double angleStep = 2 * PI / points; // ������ �������� ǥ��

		for (int i = 0; i < points; i++) {
			// ������ ���� x, y ��ǥ ���
			double angle = i * angleStep;
			int drawX = static_cast<int>(pt.x + radius * cos(angle));
			int drawY = static_cast<int>(pt.y + radius * sin(angle));
			pCanvas[drawY* canvas.cols+drawX] = color[0];
		}
	}
	void Draw_rectangle(cv::Point pt_topLeft, cv::Point pt_btmRight, cv::Scalar color=255)
	{
	
	}
};


int main()
{
	int rows = 400;
	int cols = 600;
	int channels = 1;//gray-1,color-3 
	DrawCanvas dCan(rows, cols, channels);

	const cv::Mat& canvasImage = dCan.GetCanvas();


	cv::Point pt(cols / 2 - 1, rows / 2 - 1);
	int radius = std::min(rows, cols) / 3;
	dCan.Draw_circle(pt, radius);
	

	int gap = 10;
	cv::Point ptArry[4] = { cv::Point(0 + gap,0 + gap),
		cv::Point(cols - 1 - gap,0 + gap),
		cv::Point(cols - 1 - gap,rows - 1 - gap),
		cv::Point(0 + gap,rows - 1 - gap) };
	
	dCan.Draw_line(ptArry[0], ptArry[1], cv::Scalar(255));
	dCan.Draw_rectangle(ptArry[0], ptArry[2],cv::Scalar(255));

	

	//debug point, check image watch
	int a = 0;

	return 1;
}