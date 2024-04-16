#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else if (b == 1)
		return 1;
	return GCD(b, a % b);
}

int main()
{
	int num, gcd, count;
	gcd = count = 0;
	cin >> num;

	int* treePos = new int[num];
	int* intervalArr = new int[num - 1]();
	for (int i = 0, j = 0; i < num; i++)
	{
		cin >> treePos[i];
		if (i == 0) continue;

		intervalArr[j] = treePos[i] - treePos[i - 1];

		if (j == 1)
			gcd = (intervalArr[1] > intervalArr[0]) ? GCD(intervalArr[1], intervalArr[0]) :
			GCD(intervalArr[0], intervalArr[1]);
		else if (j > 1)
			gcd = (intervalArr[j] > gcd) ? GCD(intervalArr[j], gcd) : GCD(gcd, intervalArr[j]);
		j++;
	}
	for (int i = 0; i < num - 1; i++)
		count += intervalArr[i] / gcd - 1;
	cout << count;

	delete[] treePos;
	delete[] intervalArr;
	return 0;
}