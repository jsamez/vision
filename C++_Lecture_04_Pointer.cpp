#include <iostream>
#include <string>
#include <vector>

int main()
{
	int nArray[148646] = { 1,2,3,4,5,6,7,8,9,10 };
	int* pArr = nArray;
	int lenght = sizeof(nArray) / sizeof(int);

	size_t sum = 0;
	
	sum = 0;
	for (size_t i = 0; i < lenght; i++)
		sum += pArr[i];
	std::cout << "pArr[i] sum = " << sum << std::endl;

	sum = 0;
	for (size_t i = 0; i < lenght; i++)
		sum += *(pArr + i);
	std::cout << "*(pArr + i) sum = " << sum << std::endl;

	sum = 0;
	for (size_t i = 0; i < lenght; i++)
		sum += *(pArr++);
	std::cout << "*(pArr++) sum = " << sum << std::endl;



	for (size_t i = 0; i < lenght; i++)
		std::cout << *(pArr + i) << " ";
	std::cout << std::endl; 
	
	for (size_t i = 0; i < lenght; i++)
		std::cout << pArr[i] << " ";
	std::cout << std::endl; 
	
	for (size_t i = 0; i < lenght; i++)
		std::cout << *(pArr++)<< " ";
	std::cout << std::endl;
	return 1;
}