#include <iostream>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int **arr = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = new int[n + 1];
        fill_n(arr[i], n + 1, INF);
    }

    for (int i = 0; i < m; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;

        if (arr[v1][v2] > cost)
            arr[v1][v2] = cost;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    arr[i][j] = 0;
                else if (arr[i][k] != INF && arr[k][j] != INF)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n + 1; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}