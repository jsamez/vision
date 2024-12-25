#include <iostream>

struct Point
{
	int x, y;
	Point(int _x, int _y) : x(_x), y(_y) {}
};
void DrawLine(Point pt1, Point pt2)
{
	std::cout << "pt1=" << pt1.x << "," << pt1.y << " ----> " << "pt2=" << pt2.x << "," << pt2.y << std::endl;

}

int main()
{

	
	const size_t size = 4;
	Point pt[size] = { Point(1,1),Point(100,1),Point(100,100),Point(1,100) };

	//�̰��� For���� ����Ͽ� �簢�� OutLine�� �׸��ÿ�
	DrawLine(pt[0], pt[1]);

	
	for (size_t i = 0; i < size; i++)
		DrawLine(pt[i], pt[i+1]);

	for (size_t i = 0; i < size-1; i++)
		DrawLine(pt[i], pt[i + 1]);
	DrawLine(pt[size - 1], pt[0]);//3->0
	

	for (size_t i = 0; i < size-1; i++)
		DrawLine(pt[i%size], pt[(i + 1) % size]);


	return 1;
}