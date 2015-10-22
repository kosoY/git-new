#include <iostream>
using namespace std;
	template < typename t >
	void QuickSort(t array[], int left, int right)
	{
		int i = left;
		int j = right;
		t temp;
		int pivot = array[(left + right) / 2];
		while (i <= j)
		{
			while (array[i] < pivot)
				i++;
			while (array[j] > pivot)
				j--;
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				i++;
				j--;
			}
		}
		if (left < j)
			QuickSort(array, left, j);
		if (i < right)
			QuickSort(array, i, right);
	}
	template < typename t >
	void Get(t array[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << array[i] << "-";
		}
	}
class Complex
{
private:
	struct Comp
	{
		int im;
		int re;
	};
	struct Help
	{
		double a;
		int i;
	};
	Help *arrayh;
	Comp *array;
	int size;
	bool dodat = true;
public:
	//void Inizialize();
	void QuickSort(int left, int right)
	{
		/*if (dodat == true)
		{
			arrayh = new Help[size];
			for (int i = 0; i < size; i++)
			{
				arrayh[i].a = sqrt(pow(array[i].re, 2) + pow(array[i].im, 2));
				arrayh[i].i = i;
			}
			dodat = false;
		}*/
		int i = left;
		int j = right;
		Help temp;
		int pivot = arrayh[(left+right)/2].a;
		
		while (i <= j)
		{
			while ( arrayh[i].a < pivot)
				i++;
			while ( arrayh[j].a > pivot)
				j--;
			if (i < j)
			{
				temp = arrayh[i];
				arrayh[i] = arrayh[j];
				arrayh[j] = temp;
				i++;
				j--;
			}
		}
		if (left < j)
			QuickSort( left, j);
		if (i < right)
			QuickSort(i, right);
	}
	void Set_size()
	{
		int n;
		cout << "Enter the size of array: ";
		cin >> n;
		this->size = n;
	}
	int Get_size() 
	{
		return this->size;
	}
	void Set_array()
	{
		int k;
		int h;
		for (int i = 0; i < size; i++)
		{
			cout << "x[" << i << "](real)= ";
			cin >> k;
			cout << "x[" << i << "](imagine)= ";
			cin >> h;
			array[i].re = k;
			array[i].im = h;
		}
	}
	void Get_array() 
	{
		for (int i = 0; i < size; i++)
		{
			cout << "x[" << i << "](real)= ";
			cout << arrayh[i].a << endl;
			cout << "x[" << i << "](imagine)= ";
			cout << arrayh[i].i << endl;
		}
	}
	Complex()
	{
		Set_size();
		array = new Comp[size];
		arrayh = new Help[size];
		for (int i = 0; i < size; i++)
		{
			arrayh[i].a = sqrt(pow(array[i].re, 2) + pow(array[i].im, 2));
			arrayh[i].i = i;
		}
	}
	~Complex()
	{
		delete []array;
	}
};

int main()
{
	
	int array[5];
	array[0] = 5;
	array[1] = 4;
	array[2] = 3;
	array[3] = 2;
	array[4] = 1;
	QuickSort(array, 0, 4);
	Get(array, 5);
	/*Complex Com;
	Com.Set_array();
	Com.Get_array();
	Com.QuickSort(0, Com.Get_size()-1);
	cout << "****************" << endl;
	Com.Get_array();
	cout << endl;*/
	system("pause");
}