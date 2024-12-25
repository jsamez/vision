#include <iostream>
#include <string>
#include <vector>

struct Student //data
{
	//public:
	int kor, eng, math;
	std::string name;
	double sum, avg;
};
class StudentsInfo
{
private:
	std::vector<Student> students;
	const Student* topKoreanStudent = nullptr;
	const Student* topEnglishStudent = nullptr;
	const Student* topMathStudent = nullptr;
public:
	StudentsInfo() { std::cout << "Students::Ctor" << std::endl; }
	~StudentsInfo() { std::cout << "Students::Dtor" << std::endl; }

	void SetInfo(const std::string& name, const int& kor, const int& eng, const int& math)
	{
		std::cout << "call Students::SetInfo" << std::endl;
		Student student;
		student.name = name; student.kor = kor; student.eng = eng; student.math = math;
		student.sum = kor + eng + math;
		student.avg = student.sum / 3.0;
		students.push_back(student);
	}

	void CalcBestStudent()
	{
		// Determine top students
		topKoreanStudent = &students[0];
		topEnglishStudent = &students[0];
		topMathStudent = &students[0];

		for (const auto& student : students)
		{
			if (student.kor > topKoreanStudent->kor)
				topKoreanStudent = &student;

			if (student.eng > topEnglishStudent->eng)
				topEnglishStudent = &student;

			if (student.math > topMathStudent->math)
				topMathStudent = &student;
		}
	}

	void ShowInfo()
	{
		for (const auto& student : students)
		{
			std::cout << student.name << " �л��� ���� �հ�, ����� " << student.sum << ", " << student.avg << " �Դϴ�." << std::endl;
		}
		std::cout << "\n���� ���� �ֿ�� �л��� " << topKoreanStudent->name << " �л��Դϴ�." << std::endl;
		std::cout << "���� ���� �ֿ�� �л��� " << topEnglishStudent->name << " �л��Դϴ�." << std::endl;
		std::cout << "���� ���� �ֿ�� �л��� " << topMathStudent->name << " �л��Դϴ�." << std::endl;
	}
	const std::vector<Student>& GetStudents() { return students; }
public:
	const std::string& GetTopKoreanStudent() { return topKoreanStudent->name; }
	const std::string& GetTopEnglishStudent() { return topEnglishStudent->name; }
	const std::string& GetTopMathStudent() { return topMathStudent->name; }
	

};
int main()
{
	// ����ڷκ��� ���� ������ �����ؼ� class�� ����
	std::cout << "�� ���α׷��� �л� ������ �����ϴ� ���α׷��Դϴ�." << std::endl;
	std::cout << "�л� �̸� / ��,��,�� ������ �Է��Ͻø� �л����� ������ �����ص帳�ϴ�." << std::endl;
	std::cout << "=====================================" << std::endl;

	StudentsInfo students_info;
	char addMore;
	do
	{
		std::string name;
		int kor, eng, math;
		std::cout << "�л� �̸��� �Է��ϼ���: "; std::cin >> name;
		std::cout << "���� ������ �Է��ϼ���: "; std::cin >> kor;
		std::cout << "���� ������ �Է��ϼ���: "; std::cin >> eng;
		std::cout << "���� ������ �Է��ϼ���: "; std::cin >> math;

		students_info.SetInfo(name, kor, eng, math);

		std::cout << "�߰� �л� ������ �Է��Ͻðڽ��ϱ�? (Y or N): ";
		std::cin >> addMore;
	} while (addMore == 'Y' || addMore == 'y');
	

	//best student
	students_info.CalcBestStudent();



	// Display all student information
	std::cout << "\n��� �л� ����:\n";
	//students_info.ShowInfo();

	const std::vector<Student>& students = students_info.GetStudents();

	for (const auto& student : students)
	{
		std::cout << student.name << " �л��� ���� �հ�, ����� " << student.sum << ", " << student.avg << " �Դϴ�." << std::endl;
	}
	std::cout << "\n���� ���� �ֿ�� �л��� " << students_info.GetTopKoreanStudent() << " �л��Դϴ�." << std::endl;
	std::cout << "���� ���� �ֿ�� �л��� " << students_info.GetTopEnglishStudent() << " �л��Դϴ�." << std::endl;
	std::cout << "���� ���� �ֿ�� �л��� " << students_info.GetTopMathStudent() << " �л��Դϴ�." << std::endl;

	return 1;
}