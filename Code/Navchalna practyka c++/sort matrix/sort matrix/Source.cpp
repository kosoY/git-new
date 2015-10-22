#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	int a;
	int lich = 0;
	ifstream file1;
	file1.open("In1.txt");
	while (!file1.eof())
	{
		file1 >> a;
		lich++;
	}
	int rozm;
	rozm = sqrt(lich);
	int **matrix = new int *[rozm];
	for (int i = 0; i<rozm; i++)
		matrix[i] = new int[rozm];
	file1.seekg(ios::beg);
	int i = 0;
	int j = 0;
	for (int i = 0; i < rozm; i++)
	{
		for (int j = 0; j < rozm; j++)
		{
			file1 >> a;
			matrix[i][j] = a;
		}
	}
	for (int i = 0; i < rozm; i++)
	{
		for (int j = 0; j < rozm; j++)
		{
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	file1.close();
	int rozm2;
	if (rozm % 2 == 0)
	{
		rozm2 = rozm / 2;
	}
	else
	{
		rozm2 = rozm / 2+1;
	}
   /* int **matrix2 = new int *[rozm2];
	for (int i = 0; i < rozm2; i++)
	{
		matrix2[i] = new int[rozm];
	}
	for (int i = 0; i < rozm; i++)
	{
		for (int j = 0; j < rozm2; j++)
		{
			int k = 2 * i;
			int l = 2 * j;
			matrix2[i][j] = matrix[k][l];
		}
	}
	for (int i = 0; i < rozm; i++)
	{
		for (int j = 0; j < rozm2; j++)
		{
			cout << matrix2[i][j];
		}
	}
	*/



	delete matrix;
	system("pause");

}
