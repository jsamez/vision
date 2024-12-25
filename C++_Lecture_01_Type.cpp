#include <iostream>
#include <string>
#include <vector>

//::casting::
//static_cast
//const_cast
//reinterpret_cast
//dynamic_cast
int main()
{
	std::cout << "C++_Lecture_01.cpp" << std::endl;
	//c/c++...memory data

	//single value
	int a = 0;
	unsigned char aa = 0;
	char cA = 'A';
	double _aa = 0.1f;
	float _a = 0.01f;
	//pointer
	void*         pAddr = nullptr;   //address 32bit, 64bit WORD unit
	char*         pCharAddr = nullptr;
	double*       pDbAddr = nullptr;
	*pCharAddr = 0x1;

	//group value
	struct MyStruct
	{
		int a = 0;
		unsigned char aa = 0;
		char cA = 'A';
		double _aa = 0.1f;
		float _a = 0.01f;
	};


	//array ... image processing ...database
	int Arr[10] = { 0x00, };//....1
	std::vector<int> vArr(10);//....2
	std::vector<char> vArr2(10);
	std::vector<MyStruct> vArrStruct(10);

	//= operator
	//index [0]...[N-1]
	Arr[5] = 10;
	vArr[5] = 10;

	//addre addr++...addr++
	int* pArr = &Arr[0];
	pArr++;//pointer ++
	//l-value   =   r-value
	(*pArr) = 10;

	int* pvArr = &vArr[0];
	pvArr++;
	*pvArr = 10;

	//struct
	vArrStruct[0].a = 10;
	//class = {var, fuct > struct}
	
	return 1;
}