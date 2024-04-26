#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		long long num;
		cin >> num;
		while (true)
		{
			if (isPrime(num))
				break;
			else
				num++;
		}
		cout << num;
		if (testCase != 0)
			cout << "\n";
	}
	return 0;
}