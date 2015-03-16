#include <conio.h>
#include <iostream>
#include <locale>

using namespace std;

class Urav
{
private:
int a,b,c;
double x1,x2;

public:

Urav()
{a = b = c = 0;}

void Urav::vvod(int a,int b,int c)
{
	this -> a = a;
	this ->b = b;
	this -> c = c;
}

double Urav::disc(int a,int b,int c)
{return ((b*b) - (4*a*c));}	

void Urav::reshenie(int a,int b, int c,double &x1, double &x2)
{
   x1 = ((-b + (sqrt((b*b) - 4*a*c))) / (2*a));
   x2 = ((-b - (sqrt((b*b) - 4*a*c))) / (2*a));
}

//bool Urav::proverka(int x1,int x2)
//{
//if (x1 - (int)x1 == 0 && x2 - (int)x2 == 0)
//	return 1;
//else return 0;
//}

void Urav::print(int a,int b, int c,double x1,double x2)
{
	cout << "Уравнение: " << a << "x^2 + " << b << "x + " << c;
	if (x1 != x2)
	{
		cout << endl << "Корни: " << x1 << " и " << x2; 
	}
	else 
	{
			cout << endl << "Один корень: " << x1;
	}
}

};


int main()
{
	setlocale(LC_ALL,"Russian");
	int a,b,c,n;
	double x1,x2;

	cout << "Количество уравнений: ";
	cin >> n;

	Urav *pUrav;
	pUrav = new Urav [n];
	
	for (int i = 0;i<n;i++)
	{
	cout << "Введите коэффиценты " << i+1 << " -го уравнения:" << endl;
	cout << endl << "a: ";
	cin >> a;
	cout << endl << "b: ";
	cin >> b;
	cout << endl << "c: ";
	cin >> c;
	pUrav[i].vvod(a,b,c);
	pUrav[i].reshenie(a,b,c,x1,x2);
	if (x1 - (int)x1 == 0 && x2 - (int)x2 == 0)
	{pUrav[i].print(a,b,c,x1,x2);}
	else cout << endl << "У уравнения № " << i+1 << " нет вещественных корней!" << endl;
	}

	
	
_getch();
return 0;}