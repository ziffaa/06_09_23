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
		simplify();
	}
	void setdenominator(int x)
	{
		denominator = x;
		simplify();
	}
	void set(int n, int d)
	{
		numerator = n;
		denominator = d;
		simplify();
	}
	void input()
	{
		cout << "enter numerator: ";
		cin >> numerator;
		cout << "enter denominator: ";
		cin >> denominator;
		simplify();
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
		int commondenominator = f1.getdenominator() * denominator;
		temp.setnumerator((numerator * (commondenominator / denominator)) + (f1.getnumerator() * (commondenominator / f1.getdenominator())));
		temp.setdenominator(commondenominator);
		temp.simplify();
		return temp;
	}
	Fraction subtract(Fraction f1)
	{
		Fraction temp;
		int commondenominator = f1.getdenominator() * denominator;
		temp.setnumerator((numerator * (commondenominator / denominator)) - (f1.getnumerator() * (commondenominator / f1.getdenominator())));
		temp.setdenominator(commondenominator);
		temp.simplify();
		return temp;
	}
	Fraction multiply(Fraction f1)
	{
		Fraction temp;
		temp.setnumerator(getnumerator() * f1.getnumerator());
		temp.setdenominator(getdenominator() * f1.getdenominator());
		temp.simplify();
		return temp;
	}
	Fraction divide(Fraction f1)
	{
		Fraction temp;
		temp.setnumerator(getnumerator() * f1.getdenominator());
		temp.setdenominator(getdenominator() * f1.getnumerator());
		temp.simplify();
		return temp;
	}
	Fraction()
	{
		set(0, 1);
	}
	Fraction(int n, int d)
	{
		set(n, d);
		simplify();
	}
};
void printfraction(Fraction f)
{
	cout << f.getnumerator() << " / " << f.getdenominator() << endl;
};

int main()
{
	Fraction f1;
	f1.set(776, 343);
	f1.print();

	Fraction f2(66, 33);
	f2.print();

	cout << endl;
	printfraction(f1.add(f2));
	printfraction(f1.subtract(f1.add(f2)));
	printfraction(f1.divide(f2));
	printfraction(f1.multiply(f2));
}