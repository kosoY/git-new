
#include<iostream>
#include"Complex.h"
using namespace std;

Complex::Complex(double re, double im)
{
	this->re = re;
	this->im = new double;
	*(this->im) = im;
	cout«"\nConstructor"«" re ="«re«" im ="«*(this->im);
}

Complex::Complex(Complex& complex)
{
	this->re = complex.re;
	this->im = new double;
	*(this->im) = *(complex.im);
	cout«"\nCopying Constructor"«" re ="«re«" im ="« *(this->im);
}

Complex::~Complex(){
	delete im;
	cout « "\n This is destructor";
}
double Complex::getRe()
{
	return re;
}

double Complex::getIm()
{
	return *im;
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
	this->re = this->re + complex.re;
	*(this->im) = *(this->im) + *(complex.im);
	return *this;
}
