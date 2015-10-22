#include"Complex.h"
#include <iostream>
using namespace std;

Complex::Complex(double re, double im)
{
	this->re = re;
	this->im = new double;
	*(this->im) = im;
	cout << "Constructor start" << "  re  = " << re << " im = " << im << endl;
}

Complex::Complex(Complex& complex)
{
	this->re = complex.re;
	this->im = new double;
	*(this->im) = *(complex.im);
	cout << "Constructor*cop start" << "  re  = " << re << " im = " << (*im) << endl;

}

Complex::~Complex()
{
	cout << "destructor" << endl;
	delete im;
}

double Complex::getRe()
{
	return re;
}

double Complex::getIm()
{
	return (*im);
}

void Complex::setRe(double re)
{
	this->re = re;
}

void Complex::setIm(double im)
{
	*(this->im) = im;
}

Complex Complex::add(Complex complex)
{
	this->re += complex.re;
	*(this->im) = *(this->im) + *(complex.im);
	return *this;
}