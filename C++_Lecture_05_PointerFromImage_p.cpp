
#include <iostream>
#include <string>
#include "ColorDefine.h"

int main()
{
	//cv::Mat colorImage = cv::imread("Images\\Audrey.jpg", cv::ImreadModes::IMREAD_GRAYSCALE);
	int rows = 100;
	int cols = 100;
	cv::Mat img = cv::Mat::zeros(rows, cols, CV_8UC1);



	uchar* pData = img.data;//array start address
	int width = cols;//array width size
	int height = rows;//array height size

	//Quiz .... �簢 �̹����� �߽ɿ� 255������ �����ϼ���

	//GUGUDAN
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			size_t index = row * width + col;
			if (row == (rows / 2.0) - 1 || col == (cols / 2.0) - 1)
			{
				//pData[index] = 255;
			}
			if (row == (rows / 2.0) - 1 && col == (cols / 2.0) - 1)
			{

				pData[index] = 160;
			}
		}
	}

	size_t start_row = (rows / 4) - 1;
	size_t start_col = (cols / 4) - 1;
	size_t finish_row = rows - (rows / 4) - 1;
	size_t finish_col = cols - (cols / 4) - 1;

	for (size_t row = start_row; row <= finish_row; row++)
	{
		for (size_t col = start_col; col <= finish_col; col++)
		{
			size_t index = row * width + col;
			if (row == start_row || row == finish_row || col == start_col || col == finish_col)
			{
				pData[index] = 255;
			}
		}
	}

	size_t index = 0;
	size_t center_y = height / 2 - 1;
	size_t center_x = width / 2 - 1;

	index = (center_y - 2) * width + center_x; pData[index] = 255;
	index = (center_y - 1) * width + center_x; pData[index] = 255;
	index = (center_y + 0) * width + center_x; pData[index] = 255;
	index = (center_y + 1) * width + center_x; pData[index] = 255;
	index = (center_y + 2) * width + center_x; pData[index] = 255;

	index = (center_y)*width + (center_x + 1); pData[index] = 255;
	index = (center_y)*width + (center_x + 2); pData[index] = 255;
	index = (center_y)*width + (center_x - 1); pData[index] = 255;
	index = (center_y)*width + (center_x - 2); pData[index] = 255;

	index = (center_y - 2) * width + (center_x - 2); pData[index] = 255;
	index = (center_y - 2) * width + (center_x + 2); pData[index] = 255;
	index = (center_y + 2) * width + (center_x - 2); pData[index] = 255;
	index = (center_y + 2) * width + (center_x + 2); pData[index] = 255;


	return 1;
}
