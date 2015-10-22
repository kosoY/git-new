#include <iostream>
#include"Complex.h"
using namespace std;

void main()
{
	cout << "\nThe Start\n";
	Complex test(5);
	Complex *data = new Complex();
	data->setRe(2);
	(*data).setIm(1);
	cout << "\ndata=" << data->getRe() << "+i*" << data->getIm() << "\n";
	cout << "\ntest=" << test.getRe() << "+i*" << test.getIm() << "\n";
	test = *data;
	Complex work(10, 10);
	*data = work.add(test);
	data->add(5);
	cout << "\ndata=" << data->getRe() << "+i*" << data->getIm() << "\n";
	delete data;
}