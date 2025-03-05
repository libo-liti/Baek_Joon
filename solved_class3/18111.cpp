#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int col, row, block, _min = INT_MAX, _max = 0, time = INT_MAX, height;
    cin >> row >> col >> block;
    vector<vector<int>> grid(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            int input;
            cin >> input;
            grid[i][j] = input;

            if (_min > input)
                _min = input;

            if (_max < input)
                _max = input;
        }

    while (true)
    {
        int sum = 0, _block = block;
        if (_max < _min || _min > 256)
            break;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                int value = grid[i][j] - _min;
                if (value > 0)
                {
                    sum += value * 2;
                    _block += value;
                }
                else if (value < 0)
                {
                    sum -= value;
                    _block += value;
                }
            }

        if (sum <= time && _block >= 0)
        {
            time = sum;
            height = _min;
        }
        _min++;
    }
    cout << time << " " << height;

    return 0;
}