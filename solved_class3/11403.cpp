#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    // Input
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int input;
            cin >> input;
            grid[i][j] = input;
        }
    // Floyd
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (grid[i][k] != 0 && grid[k][j] != 0)
                    grid[i][j] = 1;
            }
    // Output
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
    return 0;
}