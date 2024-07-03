#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, r, c;

int search(int firstPoint, int size, int row, int col)
{
    // 원하는 좌표에 도착했을때
    if (row == r && col == c)
        return firstPoint;

    // 한 사분면의 길이
    int len = pow(2, size) / 2;
    // 한 사분면의 칸의 개수
    int count = len * len;

    // 왼쪽 위
    if (r < row + len && c < col + len)
        return search(firstPoint, size - 1, row, col);
    // 오른쪽 위
    else if (r < row + len && c >= col + len)
        return search(firstPoint + count, size - 1, row, col + len);
    // 왼쪽 아래
    else if (r >= row + len && c < col + len)
        return search(firstPoint + count * 2, size - 1, row + len, col);
    // 오른쪽 아래
    else if (r >= row + len && c >= col + len)
        return search(firstPoint + count * 3, size - 1, row + len, col + len);
}

int main()
{
    cin >> n >> r >> c;
    cout << search(0, n, 0, 0);
    return 0;
}