#include <iostream>

using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	int getnumerator()
	{
		return numerator;
	}
	int getdenominator()
	{
		return denominator;
	}
	void setnumerator(int x)
	{
		numerator = x;
	}
	void setdenominator(int x)
	{
		denominator = x;
	}
	void set(int n, int d)
	{
		numerator = n;
		denominator = d;
	}
	void input()
	{
		cout << "enter numerator: ";
		cin >> numerator;
		cout << "enter denominator: ";
		cin >> denominator;
	}
	void print()
	{
		cout << numerator << " / " << denominator << endl;
	}
	int gcd() {
		int a = numerator;
		int	b = denominator;
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
	void simplify()
	{
		int temp = gcd();
		numerator /= temp;
		denominator /= temp;
	}
	Fraction add(Fraction f1)
	{
		Fraction temp;
		temp.setnumerator(getnumerator() + f1.getnumerator());
		return temp;
	}
	Fraction subtract(Fraction f1)
	{
		Fraction temp;
		temp.setnumerator(getnumerator() - f1.getnumerator());
	}
	Fraction multiply(Fraction f1)
	{
		Fraction temp;
		temp.setnumerator(getnumerator() * f1.getnumerator());
		temp.setdenominator(getdenominator() * f1.getdenominator());
		return temp;
	}
	Fraction divide(Fraction f1)
	{
		Fraction temp;
		temp.setnumerator(getnumerator() * f1.getdenominator());
		temp.setdenominator(getdenominator() * f1.getnumerator());
		return temp;
	}
	Fraction()
	{
		set(0, 0);
	}
	Fraction(int n, int d)
	{
		set(n, d);
	}
};

int main()
{
	Fraction f1;
	f1.set(776,343);
	f1.print();
	Fraction f2(66,33);
	f2.print();
	Fraction f3;
	f3 = f1.divide(f2);
	f3.print();
	cout << endl << f3.gcd() << endl;
	f3.simplify();
	f3.print();
	
}