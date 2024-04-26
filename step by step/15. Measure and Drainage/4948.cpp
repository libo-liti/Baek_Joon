#include <iostream>
using namespace std;

int isPrime(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int main()
{
	while (true)
	{
		int n, count;
		n = count = 0;
		cin >> n;
		if (n == 0)
			break;

		for (int i = n; ++i <= n * 2;)
			count += isPrime(i);

		cout << count << endl;
	}
	return 0;
}