#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
	Complex(double = 0, double = 0);
	Complex(Complex&);
	~Complex();
	double getRe();
	double getIm();
	void setRe(double re);
	void setIm(double im);
	Complex add(Complex);

private:
	double re;
	double *im;
};

#endif