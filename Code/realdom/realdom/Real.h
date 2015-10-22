#ifndef REAL_NUMBER_H
#define REAL_NUMBER_H
class Real
{
private:
	int *m;
	int n;
public:
	Real(int = 0, int = 1);
	short int getM();
	unsigned short int getN();
	void setM(int = 0);
	void setN(int = 0);
	void skor();
	Real add(Real first, Real second);
	Real ded(Real first, Real second);
	Real mult(Real first, Real second);
	Real div(Real first, Real second);
	Real(Real&);
	~Real();
};
#endif REAL_H#pragma once
