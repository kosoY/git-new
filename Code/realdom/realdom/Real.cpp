#include "Real.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Ukrainian");
	Real *n1 = new Real(3, 5), *n2 = new Real(), *n3 = new Real();
	n2->setM(7);
	n2->setN(4);
	cout<<"����� ����� ���i���� ="<<n1->getM()<<"/"<<n1->getN()<<endl;
	cout<<"����� ����� ���i���� ="<<n2->getM()<<"/"<<n2->getN()<<endl;
	int p;
	cout<<"�����i�� ������i� ��� ����i��� ��������"<<endl<<"��� ������ ����i��: 1"<<endl<<"��� �i����� ����i��: 2"<<endl<<"��� ��������� ����i��: 3"<<endl<<"��� ���i���� ����i��: 4"<<endl;
	cin>>p;
	cout<<"�i����i��: ";
	switch (p)
	{
	case 1: n3->add(*n1, *n2);
		cout<<n3->getM()<<"/"<<n3->getN()<<endl; break;
	case 2: n3->ded(*n1, *n2);
		cout<<n3->getM()<<"/"<<n3->getN()<<endl; break;
	case 3: n3->mult(*n1, *n2);
		cout<<n3->getM()<<"/"<<n3->getN()<<endl; break;
	case 4: n3->div(*n1, *n2);
		cout<<n3->getM()<<"/"<<n3->getN()<<endl; break;
	default: cout<<"���������� ������i ���i"<<endl;
	}
	delete(n1);
	delete(n2);
	delete(n3);
	system("pause");
}