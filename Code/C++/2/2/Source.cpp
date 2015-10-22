#include <iostream> // без .h 
#include <math.h>
#include <iomanip> // без .h

using namespace std; // для cin cout (да это зло таскать ВСЕ пространство имен std) )

const int n = 5;
const int d = -5;
const double q = -2.58;

int sign(double);
double sum(int, double[5][5], double[5][5]);
double sum(int, int, double[5][5], double[5][5]);
double sum(int, double[5][5], double[5], double[5][5]);
double sum(int, double[5][5], double[5]);

void main()
{
	double a[5][5] = { { q, 1, 0, 0, 0 }, { 1, -2, 1, 0, 0 }, { 0, 1, -2, 1, 0 }, { 0, 0, 1, -2, 1 }, { 0, 0, 0, 1, q } };
	double b[5] = { 0, d, d, d, 0 };
	double s[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
	double s_t[5][5];
	double d[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
	double x[5];
	double y[5];
	int i, j, k;

	d[0][0] = sign(a[0][0]);
	s[0][0] = sqrt(fabs(a[0][0]));
	for (k = 0; k < n; k++)
	{
		if (k != 0)
		{
			d[k][k] = sign(a[k][k] - sum(k, d, s));
			s[k][k] = sqrt(fabs(a[k][k] - sum(k, d, s)));
			cout << "s [" << k << "][" << k << "] " << s[k][k] << endl;
		}
		for (j = k + 1; j < n; j++)
		{
			s[k][j] = (a[k][j] - sum(k, j, d, s)) / (s[k][k] * d[k][k]);
			cout << "s [" << k << "][" << j << "] " << s[k][j] << endl;
		}
	}
	cout << '\n';
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << s[i][j] << setw(15);
		}
		cout << '\n';
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			s_t[i][j] = s[j][i];
		}
	}
	cout << "\n\n\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << s_t[i][j] << setw(15);
		}
		cout << '\n';
	}
	y[0] = b[0] / (s[0][0] * d[0][0]);
	for (i = 0; i < n; i++)
		y[i] = (b[i] - sum(i, d, y, s)) / (s[i][i] * d[i][i]);
	for (i = 0; i < n; i++)
		cout << y[i] << endl;
	//x[ n] = y[ n ] / s[ n ][ n ]; Выходы за пределе всего что тут... и вообще смысл в это строке?
	cout << "\n\n\n";
	for (i = n - 1; i >= 0; i--) // n-1 ! n - выход за пределы массива
		x[i] = (y[i] - sum(i, s, x)) / s[i][i];
	for (i = 0; i < n; i++)
		cout << x[i] << endl;
	cin.get();
}

double sum(int k, double d[5][5], double s[5][5])
{
	int i;
	double sum = 0;

	for (i = 0; i <= k - 2; i++)
		sum += d[i][i] * pow(s[i][k], 2);

	return sum;
}

double sum(int k, int j, double d[5][5], double s[5][5])
{
	double sum = 0;

	for (int i = 0; i <= k - 2; i++)
	{
		sum += d[i][i] * s[i][k] * s[i][j];
	}

	return sum;
}

double sum(int i, double d[5][5], double y[5], double s[5][5])
{
	double sum = 0;

	for (int k = 0; k <= i - 2; k++)
		sum += d[k][k] * y[k] * s[k][i];

	return sum;
}

double sum(int i, double s[5][5], double x[5])
{
	double sum = 0;

	for (int k = i + 1; k <= n - 1; k++)
		sum += s[i][k] * x[k];

	return sum;
}

int sign(double z)
{
	if (z > 0)
		return 1;
	else
		return -1;
}