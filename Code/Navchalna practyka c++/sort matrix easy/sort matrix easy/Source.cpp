#include <iostream>

using namespace std;

int main()
{
	const int n = 4;
	const int m = 2;
	int array[n][n];
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = rand() % 10;
		}
	}
	int array2[n][m];
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			array2[i][j] = array[i][j*2];
		}
	}	
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j]<<"  ";
		}
		cout << endl;
	}
	int fik=0;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (array2[k][i] > array2[k][j])
				{
					fik = array2[k][i];
					array2[k][i] = array2[k][j];
					array2[k][j] = fik;
				}
			}
		}
	}
	
	cout << endl;
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			array[i][j*2] = array2[i][j ];
		}
	}
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << "  ";
		}
		cout << endl;
	}
	system("pause");
}