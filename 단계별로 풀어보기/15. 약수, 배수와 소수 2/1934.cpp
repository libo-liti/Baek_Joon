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
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int num1, num2, LCD, result;
		cin >> num1 >> num2;
		LCD = (num1 > num2) ? Euclidean(num1, num2) : Euclidean(num2, num1);
		result = num1 * num2 / LCD;
		cout << result << endl;
	}
	return 0;
}