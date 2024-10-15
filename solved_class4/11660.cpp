#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    n++;

    // 배열 할당 및 초기화
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        fill(arr[i], arr[i] + n, 0);
    }

    // 배열 입력, 누적 합
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            cin >> arr[i][j];
            if (j != 0)
                arr[i][j] += arr[i][j - 1];
        }

    while (m--)
    {
        int x1, x2, y1, y2, sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        // 구간합
        for (int i = x1; i <= x2; i++)
            sum += arr[i][y2] - arr[i][y1 - 1];
        cout << sum << "\n";
    }

    // 메모리 해제
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}