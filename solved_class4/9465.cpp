#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, answer;
        cin >> n;

        // 배열 할당 및 초기화
        int **arr = new int *[2];
        for (int i = 0; i < 2; i++)
        {
            arr[i] = new int[n];
            fill(arr[i], arr[i] + n, 0);
        }

        // 배열 입력
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        arr[0][1] += arr[1][0];
        arr[1][1] += arr[0][0];

        // DP, 한칸 앞의 대각선과 두칸 앞의 대각선 비교
        for (int i = 2; i < n; i++)
        {
            arr[0][i] += max(arr[1][i - 2], arr[1][i - 1]);
            arr[1][i] += max(arr[0][i - 2], arr[0][i - 1]);
        }
        answer = max(arr[0][n - 1], arr[1][n - 1]);
        cout << answer << "\n";

        for (int i = 0; i < 2; i++)
            delete[] arr[i];
        delete[] arr;
    }
    return 0;
}