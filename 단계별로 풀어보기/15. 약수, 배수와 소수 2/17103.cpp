#include <iostream>
#include <algorithm>
using namespace std;

const int num = 1000000;
int arr[num];

int main()
{
	int testCase;

	fill(arr, arr + num, 1);

	for (int i = 2; i <= num; i++)
	{
		if (arr[i] == 1)
			for (int j = i * 2; j <= num; j += i)
				arr[j] = 0;
	}

	cin >> testCase;
	while (testCase--)
	{
		int n, count;
		count = 0;
		cin >> n;
		
		for (int i = 2; i * 2 <= n; i++)
			if (arr[i] && arr[n - i])
				count++;
		cout << count << endl;
	}
	return 0;
}