#include <iostream>
#include <string>
#include <vector>

int main()
{
	/*case1
	2x1=2
	2x2=4
	...
	9x8=72
	9x9=81
	*/

	/*case2
	2x1=2	3x1=3	...	9x1=9
	...
	2x9=18	3x9=27	...	9x9=81
	*/

	std::cout << "Case1 备备窜" << std::endl;
	for (size_t x = 2; x < 10; x++)
	{
		for (size_t y = 1; y < 10; y++)
		{
			std::cout << x << "x" << y << "=" << x * y << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "Case2 备备窜" << std::endl;
	for (size_t y = 1; y < 10; y++)
	{
		for (size_t x = 2; x < 10; x++)
		{
			std::cout << x << "x" << y << "=" << x * y << "\t";
		}
		std::cout << std::endl;
	}

	return 0;
}