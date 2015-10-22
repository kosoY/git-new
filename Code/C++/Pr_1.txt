#include<iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "Ukrainian");
	cout << "Ведiть число n:";
	int n;
	cin >> n ;
	int a;
	a = sqrt(n);
	int i, j;
	cout << "Всi простi числа,що не перевищують n :";
	for (i =2 ; i <= n; i++){
		for (j = 2; j <= a; j++)

		{
			if (i%j != 0 || i == j) {}
			else break;
			if (j == a){
				cout << i << "  ";
			}
		}					
	}
	cout << endl;
	system("pause"); }