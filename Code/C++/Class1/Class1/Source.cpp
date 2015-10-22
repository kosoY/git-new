#include <iostream>
using namespace std;

class real1
{
public:
	int chys;
	int znam;
	void gchys()
	{
		cout << "¬вед≥ть чисельник";
		cin >> chys;
	}
	void gznam()
	{
		cout << "¬вед≥ть знаменник";
		cin >> znam;
	}
	/*real1()
	{
		cout << "This is contructor";
		cout << endl;
	}
	~real1()
	{
		cout << "This is destructor";
		cout << endl;
	}
	*/
};

void main()
{
	real1 test;
    test.gchys;
    test.gznam;




	//system("cls");
	system("pause");



}