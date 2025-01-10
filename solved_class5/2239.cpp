#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid(9, vector<int>(9));
vector<pair<int, int>> _empty;

bool isPossible(int row, int col, int value)
{
    for (int i = 0; i < 9; i++)
    {
        // 세로줄 검사
        if (grid[i][col] == value)
            return false;
        // 가로줄 검사
        if (grid[row][i] == value)
            return false;

        int y = row / 3 * 3 + i / 3;
        int x = col / 3 * 3 + i % 3;

        if (grid[y][x] == value)
            return false;
    }
    return true;
}

void Search()
{
    int idx = 0;
    while (idx < _empty.size())
    {
        int y = _empty[idx].first;
        int x = _empty[idx].second;

        int value;
        if (grid[y][x] == 0)
            value = 1;
        else
        {
            if (grid[y][x] != 9)
                value = grid[y][x] + 1;
            else
                value = grid[y][x];
        }

        for (; value <= 9; value++)
            if (isPossible(y, x, value))
            {
                grid[y][x] = value;
                idx++;
                break;
            }

        // 어떤 수도 될수 없다면 다시 돌아가기
        if (value == 10)
        {
            grid[y][x] = 0;
            idx--;
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            grid[i][j] = str[j] - '0';
            if (grid[i][j] == 0)
                _empty.push_back({i, j});
        }
    }
    Search();
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << grid[i][j];
        cout << "\n";
    }
    return 0;
}