#include<iostream>
using namespace std;
const int n = 3;
void copy(double a[n][n], double m[n][n], int i, int j)
{
	for (j; j<n; j++)
		a[i][j] = m[i][j];
}
void print(double a[n][n], double b[n][n])
{
	cout<<"----------------"<<endl;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			cout<<a[i][j]<<" ";
		cout<<"|";
		for (int k = 0; k<n; k++) cout<<b[i][k]<< " ";
		cout<<endl;
	}
	cout<<"---------------"<<endl;
}
int main()
{
	cout<<"Enter the matrix of numbers("<<n<<"-"<<n<<")"<<endl;
	double a[n][n], m[n][n], b[n][n], t[n][n];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			cin>>a[i][j];
		cout<<"--------"<<endl;
	}
	double g = a[0][0];
	cout<<"The matrix: "<<endl;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			m[i][j] = 0;
			if (i == j) b[i][j] = 1; else b[i][j] = 0;
		}
	print(a, b);
	int f = 1;
	for (int k = 0; k<n - 1; k++)
	{
		if (a[k + 1][k] == 0) k++; else
			for (int i = k + 1; i<n; i++)
			{
				for (int j = k; j<n; j++)
					m[i][j] = a[k][j] * a[i][k] - a[i][j] * a[k][k];
				for (int h = 0; h<n; h++)
					t[i][h] = b[k][h] * a[i][k] - b[i][h] * a[k][k];
				copy(a, m, i, 0);
				copy(b, t, i, 0);
			}
		cout<<"step "<<f<<":"<<endl;
		f++;
		print(a, b);
	}
	copy(m, a, 0, 0);
	copy(t, b, 0, 0);
	for (int k = n - 1; k>0; k--)
	{
		if (a[k - 1][k] == 0) k--; else
			for (int i = k - 1; i >= 0; i--)
			{
				for (int j = k; j >= 0; j--)
					m[i][j] = (a[k][j] * a[i][k] - a[i][j] * a[k][k]) / abs(a[i][i]);
				for (int h = n - 1; h >= 0; h--)
					t[i][h] = (b[k][h] * a[i][k] - b[i][h] * a[k][k]) / abs(a[i][i]);
				copy(a, m, i, 0);
				copy(b, t, i, 0);
			}
		cout<<"step "<<f<<":"<<endl;
		f++;
		print(a, b);
	}
	for (int i = 0; i<n; i++)
	{
		if (a[i][i]<0)
		{
			a[i][i] *= (-1);
			for (int j = 0; j<n; j++)
				b[i][j] *= (-1);
		}
		for (int j = 0; j<n; j++)
			b[i][j] = b[i][j] / g;//a[1][1]; 
		a[i][i] = a[i][i] / g;//a[1][1];
	}
	cout<<"step "<<f<<":"<<endl;
	print(a, b);
	/*cout«"Inverse matrix:"«endl;
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
	cout«b[i][j]«" ";
	cout«endl;
	}*/
	system("pause");
}