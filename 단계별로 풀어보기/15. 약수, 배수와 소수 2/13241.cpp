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
	long long num1, num2, LCV, result;
	cin >> num1 >> num2;
	LCV = (num1 > num2) ? Euclidean(num1, num2) : Euclidean(num2, num1);
	result = num1 * num2 / LCV;
	cout << result;
	return 0;
}