#include <iostream>
#include <string>
#include <vector>

int main()
{
	// case 1
	/*2 x 1 = 2
	2 x 2 = 4

	9 x 8 = 72
	9 x 9 = 81

	case 2
	2x1=2		3x1=3	...	9x1=9

	2x9=18					9x9=81*/

	std::cout << "备备窜 1" << std::endl;
	for (size_t i = 2; i <= 9; i++)
	{
		std::cout << i << "窜 : " << std::endl;

		for (size_t j = 1; j <= 9; j++)
		{
			std::cout << i << " * " << j << " = " << i * j << std::endl;
		}

		std::cout << "\n" << std::endl;
	}

	std::cout << "备备窜 2" << std::endl;
	for (size_t j = 1; j <= 9; j++)
	{

		for (size_t i = 2; i <= 9; i++)
		{
			std::cout << i << " * " << j << " = " << i * j << "\t";
		}
		std::cout << "\n" << std::endl;
	}


	return 1;
}