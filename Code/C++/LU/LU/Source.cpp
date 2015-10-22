#include <iostream>


using namespace std;

int main()
{
	const int n = 3;
	double arrayA[n][n];
	double arrayT[n][n];
	double arrayTT[n][n];
	double arrayY[n];
	double arrayB[n];
	int arrayX[n];
	cout <<  "Enter the matrix" << endl;

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arrayA[i][j];
		}
	}*/
	arrayA[0][0] =1 ;
	arrayA[0][1] =0 ;
	arrayA[0][2] =-1 ;
	arrayA[1][0] =0 ;
	arrayA[1][1] = 4;
	arrayA[1][2] =4 ;
	arrayA[2][0] = -1;
	arrayA[2][1] =4 ;
	arrayA[2][2] =14 ;

	for (int i = 0; i < n; i++)
	{
		cin >> arrayB[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arrayA[i][j] << "  ";
		}
		cout << endl;
	}
	double S;
	arrayT[0][0] = arrayA[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
				if (i == j)
				{
					S = 0;
					for (int k = 0; k < i ; k++)
					{
						S = S + arrayT[k][i] * arrayT[k][i];
					}
					arrayT[i][j] = sqrt(arrayA[i][j] - S);
				}
				if (i < j)
				{
					S = 0;
					for (int k = 0; k < i ; k++)
					{
						S = S + arrayT[k][i] * arrayT[k][i];
					}
					arrayT[i][j] = (arrayA[i][j] - S) / arrayT[i][i];
				}
				if (i > j)
				{
					arrayT[i][j] = 0;
				}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arrayTT[i][j] = arrayT[j][i];
		}
	}
	arrayY[0] = arrayB[0] * arrayT[0][0];
	for (int i = 1; i < n; i++)
	{
		S = 0;
		for (int k = 0; k < i ; k++)
		{
			S = S + arrayT[k][i] * arrayY[k];
		}
		arrayY[i] = (arrayB[i] - S) / arrayT[i][i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << arrayY[i] << "  ";
	}
	arrayX[n-1] = arrayY[n-1] / arrayT[n-1][n-1];
	for (int i = n - 1; i >= 0; i--)
	{
		S = 0;
		for (int k = i+1 ; k < n; k++)
		{
			S = S + arrayT[i][k] * arrayX[k];
		}
		arrayX[i] = (arrayY[i] - S) / arrayT[i][i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << arrayX[i] << "  ";
	}
	system("pause");
	
	return 0;

}