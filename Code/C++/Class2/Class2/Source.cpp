#include <iostream>

using namespace std;

class real1
{
private:
	int chys;
	int znam;
public:
	real1& operator =(int);
	void get_real()
	{
		cout << "Chyselnuk:";
		cin >> chys;
		cout << "Znamenuk:";
		cin >> znam;
	}
	void set_real()
	{
		cout << "Chyselnuk:";
		cout << chys << endl;
		cout << "Znamenuk:";
		cout << znam << endl;
	}
};
real1& real1::operator=(int a)
{
	chys = a;
	return *this;
}

void main()
{
	real1 obg;
	real1 obg1;
	obg.get_real();
	obg1.get_real();
	obg = 1;
	obg.set_real();
	system("pause");
}