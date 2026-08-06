#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 1;
    int n = s.size();
    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        grid[i][i] = 1;

    for (int i = 0; i < n - 1; i++)
        if (s[i] == s[i + 1])
        {
            grid[i][i + 1] = 1;
            answer = 2;
        }

    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && grid[i + 1][j - 1] == 1)
            {
                grid[i][j] = 1;
                answer = j - i + 1;
            }
        }
    }

    return answer;
}