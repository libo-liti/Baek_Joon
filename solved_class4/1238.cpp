#include <iostream>
using namespace std;
const int MAX = 1000001;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m, x, max = 0;
    cin >> n >> m >> x;
    int **arr = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = new int[n + 1];
        fill_n(arr[i], n + 1, MAX);
    }

    for (int i = 0; i < m; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        arr[v1][v2] = cost;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    arr[i][j] = 0;
                else
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (max < arr[i][x] + arr[x][i])
            max = arr[i][x] + arr[x][i];

    cout << max;

    for (int i = 0; i < n + 1; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}