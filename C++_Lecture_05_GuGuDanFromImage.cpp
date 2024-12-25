
#include <iostream>
#include <string>
#include "ColorDefine.h"

int main()
{
	//cv::Mat colorImage = cv::imread("Images\\Audrey.jpg", cv::ImreadModes::IMREAD_GRAYSCALE);
	int rows = 10;
	int cols = 10;
	cv::Mat img = cv::Mat::zeros(rows, cols, CV_8UC1);

	uchar* pData = img.data;//array start address
	int width = cols;//array width size
	int height = rows;//array height size

	for (size_t step = 1; step < rows; step++)
	{
		for (size_t dan = 2; dan < cols; dan++)
		{
			size_t index = step * width + dan;
			pData[index] = step * dan;
		}
	}
	return 1;
}