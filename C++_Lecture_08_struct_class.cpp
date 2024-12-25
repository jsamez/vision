#include <iostream>
#include <string>
#include <vector>

struct Student //data
{
	//public:
	int kor, eng, math;
	std::string name;
	double sum, avg;
	Student()
		: kor(0), eng(0), math(0), name(""), sum(0.0), avg(0.0)
	{
	}

	void calculateSumAndAverage()
	{
		sum = kor + eng + math;
		avg = sum / 3.0;
	}
};

class CStudent //data+action
{
private:
	//member variables
	int kor, eng, math;
	std::string name;
	double sum, avg;
	//member functions
public:
	CStudent()//creator...ctor
		: kor(0)//member initialized
		, eng(0)
		, math(0)
		, name("hong")
		, sum(0.0)
		, avg(0.0)
	{
		//kor = eng = math = 0;
		//name = "hong";
		//sum = avg = 0.;
	}
	~CStudent() {}//destroy...dtor
protected:

};

int main()
{
	std::vector<Student> students;
	char addMore;
	do
	{
		Student student;

		std::cout << "�л� �̸��� �Է��ϼ���: ";
		std::cin >> student.name;

		std::cout << "���� ������ �Է��ϼ���: ";
		std::cin >> student.kor;

		std::cout << "���� ������ �Է��ϼ���: ";
		std::cin >> student.eng;

		std::cout << "���� ������ �Է��ϼ���: ";
		std::cin >> student.math;

		student.calculateSumAndAverage();

		students.push_back(student);

		std::cout << student.name << " �л��� ���� �հ�, ����� " << student.sum << ", " << student.avg << " �Դϴ�." << std::endl;

		std::cout << "�߰� �л� ������ �Է��Ͻðڽ��ϱ�? (Y or N): ";
		std::cin >> addMore;

	} while (addMore == 'Y' || addMore == 'y');

	// Display all student information
	std::cout << "\n��� �л� ����:\n";
	
	
	//for(std::vector<Student>::iterator iter = students.begin(); iter != students.end(); iter++)
	for (const auto& student : students)
	{
		std::cout << student.name << " �л��� ���� �հ�, ����� " << student.sum << ", " << student.avg << " �Դϴ�." << std::endl;
	}

	// Determine top students
	const Student* topKoreanStudent = &students[0];
	const Student* topEnglishStudent = &students[0];
	const Student* topMathStudent = &students[0];

	for (const auto& student : students)
	{
		if (student.kor > topKoreanStudent->kor)
			topKoreanStudent = &student;

		if (student.eng > topEnglishStudent->eng)
			topEnglishStudent = &student;

		if (student.math > topMathStudent->math)
			topMathStudent = &student;
	}

	std::cout << "\n���� ���� �ֿ�� �л��� " << topKoreanStudent->name << " �л��Դϴ�." << std::endl;
	std::cout << "���� ���� �ֿ�� �л��� " << topEnglishStudent->name << " �л��Դϴ�." << std::endl;
	std::cout << "���� ���� �ֿ�� �л��� " << topMathStudent->name << " �л��Դϴ�." << std::endl;




	return 1;
}