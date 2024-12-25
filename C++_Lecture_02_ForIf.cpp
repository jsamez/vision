#include <iostream>
#include <string>
#include <vector>

int main()
{
	//제어문 : 조건문,반복문
	for (int i = 0; i < 10; i++)//반복
	{
		if (i % 2 == 0)//조건
			std::cout << "i_e = " << i << std::endl;
		else if (i % 2 != 0)//조건
			std::cout << "i_o = " << i << std::endl;
		else
			std::cout << "default" << std::endl;
	}

	std::vector<int> v(10);
	size_t sz = v.size();
	for (size_t i = 0; i < v.size(); i++)
		std::cout << "v = " << v[i] << std::endl;



	//size = (-)...array 
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2 == 0)//조건
			std::cout << "i = " << i << std::endl;
	}




	for (size_t row = 0; row < 10; row++)
	{
		for (size_t col = 0; col < 10; col++)
		{
			std::cout << "[row,col] = " << row <<" , "<<col << std::endl;
		}
	}
	return 1;
}