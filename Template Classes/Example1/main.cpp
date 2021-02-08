#include<iostream>
#include"Graph.h"
#define PI 3.14
using namespace std;
int main()
{
	Graph<float, double> g;
	for (int i = 0; i <= 3; i++)
	{
		g.AddValue(2 * cos(PI / 4 * i + PI / 3));
	}
	for (int i = 4; i <= 5; i++)
	{
		g += (2 * cos(PI / 4 * i + PI / 3));
	}
	cout << "Max:" << g.getMax() << endl;
	cout << "Min:" << g.getMin() << endl;


	system("pause");
}