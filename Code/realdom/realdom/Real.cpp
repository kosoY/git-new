#include "Real.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Ukrainian");
	Real *n1 = new Real(3, 5), *n2 = new Real(), *n3 = new Real();
	n2->setM(7);
	n2->setN(4);
	cout<<"Перше число дорiвнює ="<<n1->getM()<<"/"<<n1->getN()<<endl;
	cout<<"Друге число дорiвнює ="<<n2->getM()<<"/"<<n2->getN()<<endl;
	int p;
	cout<<"Виберiть операцiю яку потрiбно виконати"<<endl<<"Щоб додати введiть: 1"<<endl<<"Щоб вiдняти введiть: 2"<<endl<<"Щоб помножити введiть: 3"<<endl<<"Щоб подiлити введiть: 4"<<endl;
	cin>>p;
	cout<<"Вiдповiдь: ";
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
	default: cout<<"Некоректно введенi данi"<<endl;
	}
	delete(n1);
	delete(n2);
	delete(n3);
	system("pause");
}