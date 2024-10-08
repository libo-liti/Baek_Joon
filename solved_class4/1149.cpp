#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int cost[3];
    cin >> n;
    int **arr = new int *[n + 1];

    for (int i = 0; i < n + 1; i++)
        arr[i] = new int[3];

    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[0][2] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + cost[0];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + cost[1];
        arr[i][2] = min(arr[i - 1][1], arr[i - 1][0]) + cost[2];
    }
    cout << min({arr[n][0], arr[n][1], arr[n][2]});

    for (int i = 0; i < n + 1; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}