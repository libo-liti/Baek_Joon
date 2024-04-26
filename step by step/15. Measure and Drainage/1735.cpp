#include <iostream>
using namespace std;

int Euclidean(int a, int b)
{
	if (b == 0)
		return a;
	else if (b == 1)
		return 1;

	return Euclidean(b, a % b);
}

int main()
{
	int a, b, c, d, denominator, numerator, LCD;
	cin >> a >> b >> c >> d;
	denominator = b * d;
	numerator = a * d + b * c;
	LCD = (denominator > numerator) ? Euclidean(denominator, numerator) : Euclidean(numerator, denominator);
	cout << numerator / LCD << " " << denominator / LCD;
	return 0;
}