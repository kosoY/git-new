#include < iostream >

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	const int n = 9;
	int i = 0;
	int j = 0;
	double a[n + 1];
	double b[n + 1];
	for (i; i <= n; i++)//Зчитування з клавіатури даних
	{
		cin >> a[i];
	}
	i = 0;
	for (i; i <= n; i++)//Виведення на екран вхідних даних
	{
		cout << a[i] << "    ";
	}
	int k = 0;
	cout << endl;
	for (i = 0; i < n; i++)//Заповнення додаткового масиву якщо два числа в порядку зростання записуєм в масив додатковий 1 якщо наступних два в порядку зростання 
		//записуєм 2 
	{
		if (a[i] < a[i + 1])
		{
			k = k + 1;
			b[i] = k;
		}
		else
		{
			k = 0;      //якщо в порядку спадання записуєм  0
			b[i] = k;
		}
	}
	b[n] = 0;
	i = 0;
	int maxi = 0;
	i = 0;
	for (i; i <= n; i++)   //Знаходим мак елемент масиву додаткового
	{
		if (b[i] > maxi)
		{
			maxi = b[i];
		}
	}
	i = 0;
	int l = 0;
	int f = 0;
	for (i; i <= n; i++)    //Шукаєм чмсла які дорівнюють макс і ввиводим
	{
		l = i;
		if (b[i] == 0)
		{
			f = f + 1;
		}
		if (f == 10 || maxi == 0)
		{
			cout << "Всi числа в порядку спадання" << endl;
			break;
		}
		if (f == 10 || maxi == n)
		{
			cout << "Всi числа в порядку зростання" << endl;
			break;
		}
		if (b[i] == maxi)
		{
			cout << "Найдовша частина масиву в порядку зростання:";
			for (j = i - maxi + 1; j <= l + 1; j++)
			{
				cout << a[j];
			}
			cout << endl;
		}

	}
	system("pause");
	return 0;
}