#include "Real.h"
#include<iostream>
using namespace std;
Real::Real(int m, int n)
{
	this->m = new int;
	*(this->m) = m;
	this->n = n;
}
Real::Real(Real& re)
{
	this->m = new int;
	*(this->m) = *re.m;
	n = re.n;
	cout<<"Конструктор копiювання"<<endl;
}
short int Real::getM()
{
	return *m;
}
unsigned short int Real::getN()
{
	return n;
}
void Real::setM(int m)
{
	*(this->m) = m;
}
void Real::setN(int n)
{
	this->n = n;
}
Real Real::add(Real first, Real second)
{
	if (first.n == second.n)
	{
		*m = (*first.m + *second.m);
		n = first.n;
	}
	else
	{
		*m = (*first.m * second.n) + (first.n * *second.m);
		n = first.n * second.n;
	}
	skor();
	return *this;
}
Real Real::ded(Real first, Real second)
{
	if (first.n == second.n)
	{
		*m = (*first.m - *second.m);
		n = first.n;
	}
	else
	{
		*m = (*first.m * second.n) - (first.n * *second.m);
		n = first.n * second.n;
	}
	skor();
	return *this;
}
Real Real::mult(Real first, Real second)
{
	*m = *first.m**second.m;
	n = first.n*second.n;
	skor();
	return *this;
}
Real Real::div(Real first, Real second)
{
	*m = *first.m*second.n;
	n = first.n**second.m;
	skor();
	return *this;
}
void Real::skor()
{
	int k = abs(*m), p = abs(n);
	while (k != p)
	{
		if (k>p) k = k - p; 
		else p = p - k;
	}
	*m = *m / k;
	n = n / k;
}
Real::~Real()
{
	cout<<"Спрацював деструктор"<<endl;
}