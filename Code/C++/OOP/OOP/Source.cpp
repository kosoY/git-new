#include <iostream>
#include"Header.h"

using namespace std;

int main()
{
	array obj;
	obj.set_array();
	obj.get_array();
	//array obj2;
	//obj2.set_array();
	//obj2.get_array();
	obj >> 1;
	
	obj << 1;
	system("pause");
}