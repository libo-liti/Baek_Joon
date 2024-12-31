#include <iostream>
#include <vector>
using namespace std;

int answer;
int n, m;

// 시작점을 매개변수로
void Search(vector<vector<char>> grid, int row, int col)
{
    // 범위 체크
    if (row + 7 >= n || col + 7 >= m)
        return;

    char pre = grid[row][col];
    int change = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 0 && j == 0)
                continue;

            // 이전 색과 다르면 통과
            if (grid[row + i][col + j] != pre)
            {
                pre = grid[row + i][col + j];
                continue;
            }
            else
            {
                if (pre == 'W')
                    grid[row + i][col + j] = 'B';
                else if (pre == 'B')
                    grid[row + i][col + j] = 'W';

                pre = grid[row + i][col + j];
                change++;
            }
        }
        // 행의 첫번째 색은 이전 행의 마지막 색과 같아야 하는데 위의 코드를 수정하기 싫어서...
        if (pre == 'W')
            pre = 'B';
        else if (pre == 'B')
            pre = 'W';
    }
    // change 만큼 바꿔야 한다면 64 - change만큼은 올바르다는 것
    change = min(64 - change, change);
    answer = min(answer, change);
}

int main()
{
    cin >> n >> m;
    answer = n * m;
    // 초기화
    vector<vector<char>> grid(n, vector<char>(m));

    // 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Search(grid, i, j);

    cout << answer;
    return 0;
}