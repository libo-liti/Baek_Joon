#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vOut;
vector<int> vIn;

int whiteN;
int BlueN;

void dfs(int startX, int startY, int size)
{
    int tem = 0;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (vOut[startX + i][startY + j] == 1)
                tem++;

    // 모두 1인 경우
    if (tem == size * size)
    {
        BlueN++;
        return;
    }
    // 모두 0인 경우
    else if (tem == 0)
    {
        whiteN++;
        return;
    }
    else
    {
        dfs(startX, startY, size / 2);
        dfs(startX + size / 2, startY, size / 2);
        dfs(startX + size / 2, startY + size / 2, size / 2);
        dfs(startX, startY + size / 2, size / 2);
    }
}

int main()
{
    int n;
    cin >> n;

    vIn.resize(n, 0);
    vOut.resize(n, vIn);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> vOut[i][j];

    dfs(0, 0, n);

    cout << whiteN << endl
         << BlueN;
    return 0;
}