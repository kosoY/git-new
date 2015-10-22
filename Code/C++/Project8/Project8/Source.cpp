#include <iostream>
#include <string>
#include <locale>
#include <fstream>

using namespace std;

const int n = 4;
const int m = 3;
void gays1(double array0[n][n], double array00[n][n])
{
	int l;
	double r = 0;
	double res = 0;
	double fik;
	double amax;
	/*for (int k = 0; k < n; k++)
	{
	amax = array0[k][k];
	l = k;
	for (int i = k + 1; i < n; i++)
	{
	l = k;
	if (array0[i][k]>amax)
	{
	l = i;
	}
	if (l != k)
	{
	for (int s = 0; s < n; s++)
	{
	fik = array0[l][s];
	array0[l][s] = array0[k][s];
	array0[k][s] = fik;
	}
	}
	}
	}*/
	for (int k = 0; k < n; k++)
	{

		r = 1 / array0[k][k];
		for (int j = 0; j < n; j++)
		{
			array0[k][j] = array0[k][j] * r;
			array00[k][j] = array00[k][j] * r;
		}
		for (int i = k + 1; i < n; i++)
		{
			res = array0[i][k];
			for (int z = 0; z < n; z++)
			{
				array0[i][z] = array0[i][z] - array0[k][z] * res;
				array00[i][z] = array00[i][z] - array00[k][z] * res;
			}
		}
	}
	for (int k = n - 1; k >= 0; k--)
	{
		for (int i = k - 2; i >= 0; i--)
		{
			res = array0[i][k];
			for (int z = n - 1; z >= 0; z--)
			{
				array0[z][i] = array0[z][i] - array0[z][k] * res;
				array00[z][i] = array00[z][i] - array00[z][k] * res;
			}
		}
	}
}


void gays2(double array0[m][m], double array00[m][m])
{
	double r = 0;
	double res = 0;
	for (int k = 0; k < m; k++)
	{
		r = 1 / array0[k][k];
		for (int j = 0; j < m; j++)
		{
			array0[k][j] = array0[k][j] * r;
			array00[k][j] = array00[k][j] * r;
		}
		for (int i = k + 1; i < m; i++)
		{
			res = array0[i][k];
			for (int z = 0; z < m; z++)
			{
				array0[i][z] = array0[i][z] - array0[k][z] * res;
				array00[i][z] = array00[i][z] - array00[k][z] * res;
			}
		}
	}
	for (int k = m - 1; k >= 0; k--)
	{
		for (int i = k - 2; i >= 0; i--)
		{
			res = array0[i][k];
			for (int z = m - 1; z >= 0; z--)
			{
				array0[i][z] = array0[i][z] - array0[k][z] * res;
				array00[i][z] = array00[i][z] - array00[k][z] * res;
			}
		}
	}
}


int main()
{
	const int m = 3;
	const int n = 4;
	double array0[n][n];
	ifstream fin;
	fin.open("IN1.txt", ios::out);
	double a;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> a;
			array0[i][j] = a;
		}
	}
	fin.close();
	fin.seekg(ios::beg);
	ifstream fin1;
	fin1.open("IN2.txt", ios::out);
	double array1[n][n];
	double b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin1 >> b;
			array1[i][j] = b;
		}
	}
	fin1.close();
	fin1.seekg(ios::beg);
	ifstream fin2;
	fin2.open("IN3.txt", ios::out);
	double array2[m][m];
	double c;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fin2 >> c;
			array2[i][j] = c;
		}
	}
	fin2.close();
	fin2.seekg(ios::beg);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array0[i][j] << "  ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array1[i][j] << "  ";
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << array2[i][j] << "  ";
		}
		cout << endl;
	}
	double array00[n][n];
	double array11[n][n];
	double array22[m][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				array00[i][j] = 1;
			else
				array00[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				array11[i][j] = 1;
			else
				array11[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j)
				array22[i][j] = 1;
			else
				array22[i][j] = 0;
		}
	}

	gays1(array0, array00);
/*	double lik;
	double lik1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			lik = array0[i][j];
			array0[i][j] = array0[j][i];
			array0[j][i] = lik;
			lik1 = array00[i][j];
			array00[i][j] = array00[j][i];
			array00[j][i] = lik1;
		}
	}
gays1(array1, array11);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			lik = array0[i][j];
			array0[i][j] = array0[j][i];
			array0[j][i] = lik;
			lik1 = array00[i][j];
			array00[i][j] = array00[j][i];
			array00[j][i] = lik1;
		}
	}
	*/



	//gays1(array1, array11);
	//gays2(array2, array22);


/*	double fik;
	double amax;
	int l;
	for (int k = 0; k < n; k++)
	{
		amax = array0[k][k];
		l = k;
		for (int i = k + 1; i < n; i++)
		{
			l = k;
			if (array0[i][k]>amax)
			{
				l = i;
			}
			if (l != k)
			{
				for (int s = 0; s < n; s++)
				{
					fik = array0[l][s];
					array0[l][s] = array0[k][s];
					array0[k][s] = fik;
				}
			}
		}
	}
	*/





	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array00[i][j] << "  ";
		}
		cout << endl;
	}






	
	


	system("pause");
	return 0;

}