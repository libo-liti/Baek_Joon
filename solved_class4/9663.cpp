#include <iostream>
using namespace std;

int n, answer;
bool col[15];

bool Left_Diagonal(int **arr, int row, int col)
{
    for (int i = 1; i < n; i++)
    {
        if (row - i < 0 || col - i < 0)
            return true;
        if (arr[row - i][col - i])
            return false;
    }
    return true;
}

bool Right_Diagonal(int **arr, int row, int col)
{
    for (int i = 1; i < n; i++)
    {
        if (row - i < 0 || col + i >= n)
            return true;
        if (arr[row - i][col + i])
            return false;
    }
    return true;
}

void DFS(int **arr, int row)
{
    for (int i = 0; i < n; i++)
    {
        if (col[i])
            continue;
        if (Left_Diagonal(arr, row, i) == false)
            continue;
        if (Right_Diagonal(arr, row, i) == false)
            continue;
        arr[row][i] = 1;
        col[i] = true;

        if (row + 1 < n)
            DFS(arr, row + 1);
        if (row == n - 1)
            answer++;

        arr[row][i] = 0;
        col[i] = false;
    }
}

int main()
{
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n]{};
    DFS(arr, 0);
    cout << answer;
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}