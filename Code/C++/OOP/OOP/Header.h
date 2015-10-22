#ifndef HEADER_H
#define HEADER_H
#include<iostream>

using namespace std;

class array
{
protected:
	int **a;
	int size;
	void set_size()
	{
		int a;
		cout << "Enter the size of matrix: ";
		cin >> a;
		this->size = a;
	}
public:
	array()
	{
		set_size();
		a = new int*[];
			for (int i=0; i < size; i++)
			{
				a[i] = new int[size];
			}
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					a[i][j]=0;
				}
			}
	}
	array(int a00)
	{
		//set_size();
		this->size = 1;
		a = new int*[];
		for (int i = 0; i < size; i++)
		{
			a[i] = new int[size];
		}
		a[0][0] = a00;
	}
	array(array &d)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->a[i][j] = d.a[i][j];
			}
		}
	}
	~array()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] a[i];
		}
	}
	void get_array()
	{
		cout << "The matrix:" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << a[i][j]<<"  ";
			}
			cout << endl;
		}
	}
	void set_array()
	{
		cout << "Enter the matrix" << endl;;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << "x[" << i << "]" << "[" << j << "]= ";
				cin >> a[i][j];
			}
		}
	}
	array& operator +(array &obj)
	{
		if (this->size < obj.size)
		{
			int **g;
			g = new int*[];
			for (int i = 0; i < size; i++)
			{
				g[i] = new int[size];
			}
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					g[i][j] = a[i][j];
				}
			}
			for (int i = 0; i < size; i++)
			{
				delete[] a[i];
			}
			a = new int*[];
			for (int i = 0; i < obj.size; i++)
			{
				a[i] = new int[obj.size];
			}
			for (int i = 0; i < obj.size; i++)
			{
				for (int j = 0; j < obj.size; j++)
				{
					a[i][j] = 0;
				}
			}
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					a[i][j] = g[i][j];
				}
			}
			this->size = obj.size;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					this->a[i][j] += obj.a[i][j];
				}
			}
		}
		else
		{
			for (int i = 0; i < obj.size; i++)
			{
				for (int j = 0; j < obj.size; j++)
				{
					this->a[i][j] += obj.a[i][j];
				}
			}
		}
		return *this;
	}
	array& operator =(array &obj)
	{
		for (int i = 0; i < obj.size; i++)
		{
			for (int j = 0; j < obj.size; j++)
			{
				this->a[i][j] = obj.a[i][j];
			}
		}
		return *this;
	}
	friend array& operator +(array &obj, int a)
	{
		array obj1(a);
		obj + obj1;
		return obj;
	}
	friend array& operator +(int a, array &obj)
	{
		array obj1(a);
		obj + obj1;
		return obj;
	}
	array& operator >>(int i)
	{
		set_size();
		a = new int*[];
		for (int i = 0; i < size; i++)
		{
			a[i] = new int[size];
		}
		set_array();
		return *this;
	}
	const array& operator <<(int i)
	{
		get_array();
		return *this;
	}
};

#endif