#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio;
    int n, sum = 0;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
        sum += arr[i] * (n - i);
    cout << sum;
    return 0;
}