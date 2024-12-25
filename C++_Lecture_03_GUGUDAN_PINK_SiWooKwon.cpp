#include <iostream>
#include <string>
#include <vector>

int main()
{
	//case 1
	for (size_t i = 2; i < 10; i++)
	{
		for (size_t j = 1; j < 10; j++)
		{
			std::cout << i << " * " << j << " = " << i * j << std::endl;
		}
	}


	for (size_t i = 1; i < 10; i++)
	{
		for (size_t j = 2; j < 10; j++)
		{
			std::cout << j << " * " << i << " = " << i * j << "\t";
		}
		std::cout << "\n";
	}

	return 0;
}