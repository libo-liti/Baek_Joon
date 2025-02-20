#include <iostream>
using namespace std;

int main()
{
    int testCase;
    long long arr[100] = {1, 1, 1, 2, 2};

    for (int i = 5; i < 100; i++)
        arr[i] = arr[i - 1] + arr[i - 5];

    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;

        cout << arr[n - 1] << "\n";
    }
    return 0;
}