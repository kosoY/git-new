#include <iostream>

using namespace std;

int main()
{
	int a;
	cout << "Enter number";
	cin >> a;
	int b;
	while (a > 0)
	{
		b = a % 10;
		cout << b;
		a = a / 10;
	}
}