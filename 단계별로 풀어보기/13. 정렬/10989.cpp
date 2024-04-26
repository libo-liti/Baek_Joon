#include <iostream>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int num;
	int arr[10001] = { 0 };
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int n;
		cin >> n;
		arr[n]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			cout << i << "\n";
	}
	return 0;
}