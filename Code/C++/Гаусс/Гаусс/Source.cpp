#include <iostream>
#include <string>
#include <locale>
#include <fstream>

using namespace std;


int main()
{
	const int m = 3;
	const int n = 4;
	double array0[n][n*2];
	ifstream fin;
	fin.open("IN1.txt",ios::out);
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
	fin1.open("IN2.txt",ios::out);
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
	fin2.open("IN3.txt",ios::out);
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
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array00[i][j] = array0[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array11[i][j] = array1[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			array22[i][j] = array2[i][j];
		}
	}
   for (int i = 0; i < n ; i++)
	{
		for (int j = n; j < n*2 ; j++)
		{
			if (j-i == 4)
				array00[i][j] = 1;
			else
				array00[i][j] = 0;
		}
	}

	for (int i = 0; i < n ; i++)
	{
		for (int j = n; j < n * 2; j++)
		{
			if (j-i == 4)
			{
				array11[i][j] = 1;
			}
			else
				array11[i][j] = 0;
		}
	}

	for (int i = 0; i < m ; i++)
	{
		for (int j = m; j < m*2 ; j++)
		{
			if (j-i == 3)
				array22[i][j] = 1;
			else
				array22[i][j] = 0;
		}
	}
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n * 2; j++)
		{
			cout << array00[i][j]<<"  ";
		}
		cout << endl;
	}

	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n * 2; j++)
		{
			cout << array11[i][j]<<"  ";
		}
		cout << endl;
	}

	for (int i = 0; i < m ; i++)
	{
		for (int j = 0; j < m * 2; j++)
		{
			cout << array22[i][j]<<"  ";
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = n; j < n * 2; j++)
		{
			if (j - i == 4)
			{
				array0[i][j] = 1;
			}
			else
				array0[i][j] = 0;
		}
	}
	









	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = 0 + i; k < n*2; k++)
			{

				array00[j][k] = array0[i][k] - (array0[i][i] / array0[j][i] * array0[j][k]);

			}
		}
	}
	cout << endl;
	cout << array00[0][7] << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n*2 ; j++)
		{
			cout << array00[i][j] << "  ";
		}
		cout << endl;
	}
	double g = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j > i)
			{
				g = array00[i][j];
				array00[i][j] = array00[j][i];
				array00[j][i] = g;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j > i)
			{
				g = array0[i][j];
				array0[i][j] = array0[j][i];
				array0[j][i] = g;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j < n*2; j++)
		{
			if (j > i)
			{
				g = array00[i][j];
				array00[i][j] = array00[j][i];
				array00[j][i] = g;
			}
		}
	}














	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = 0 + i; k < n * 2; k++)
			{

				array00[j][k] = array0[i][k] - (array0[i][i] / array0[j][i] * array0[j][k]);

			}
		}
	}





	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2; j++)
		{
			cout << array00[i][j] << "  ";
		}
		cout << endl;
	}









	/*
	double g = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j > i)
			{
				g = array2[i][j];
				array[i][j] = array2[j][i];
				array[j][i] = g;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		array2[0][i] = array[0][i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = 0 + i; k < n; k++)
			{

				array2[j][k] = array[i][k] - (array[i][i] / array[j][i] * array[j][k]);
                
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array2[i][j] << "        ";
		}
		cout << endl;
	}
	*/
	system("pause");
	return 0;

}