#include <iostream>
#include <string>
#include <vector>

void fnSwap(int* lhs = nullptr, int* rhs = nullptr)
{
	if (lhs != nullptr && rhs != nullptr)
	{
		int tmp = *lhs;
		*lhs = *rhs;
		*rhs = tmp;
	}	
}

void fnSwap(int& lhs, int& rhs)
{
	int tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	std::cout << "a = " << a << " b = " << b << std::endl;
	fnSwap(&a, &b);
	std::cout << "a = " << a << " b = " << b << std::endl;
	fnSwap(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;

	return 1;
}