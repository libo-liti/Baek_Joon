#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 배열 초기화
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        fill(arr[i], arr[i] + n, 0);
    }

    // Input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 1; j++)
            cin >> arr[i][j];

    // 밑에서부터 위로 올라가기
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j < i + 1; j++)
            arr[i][j] = max(arr[i + 1][j], arr[i + 1][j + 1]) + arr[i][j];

    // answer
    cout << arr[0][0];

    // 메모리 해제
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}