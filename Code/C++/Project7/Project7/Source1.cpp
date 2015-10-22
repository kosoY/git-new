#ifndef COMPLEX_H
#define COMPLEX_H 

class Complex
{
private:
	double re;
	double *im;
public:
	Complex(double = 0, double = 0);
	Complex(Complex&);
	~Complex();
	double getRe();
	double getIm();
	void setRe(double = 0);
	void setIm(double = 0);
	Complex add(Complex);
};

#endif