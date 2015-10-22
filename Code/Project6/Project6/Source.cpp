#include <iostream>

using namespace std;


class Racion
{
public:
	double* a = new(double);
	double b;
	double sum(int a, int l)
	{
		double m;
		m = a + l;
		return m;
	}
	double riz(int k, int l)
	{
		double m;
		m = k - l;
		return m;
	}
	double dob(int k, int l)
	{
		double m;
		m = k * l;
		return m;
	}
	double dil(int k, int l)
	{
		double m;
		m = k / l;
		return m;
	}
	Racion()
	{
		a = 0;
		b = 0;
	}
	~Racion();


};

int main()
{
	Racion* obj1;
	obj1 = new(Racion);
	double a=5;
	double b=5;
	cout << obj1->sum(a, b) << endl;
	cout << obj1->riz(a, b) << endl;
	system("pause");
	return 0;

}