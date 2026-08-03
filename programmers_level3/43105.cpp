#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int size = triangle.size();
    vector<int> dp(size, 0);

    dp[0] = triangle[0][0];
    for (int row = 1; row < size; row++)
    {
        for (int col = row; col >= 0; col--)
        {
            if (col == row)
                dp[col] = dp[col - 1] + triangle[row][col];
            else if (col == 0)
                dp[col] = dp[0] + triangle[row][col];
            else
                dp[col] = max(dp[col - 1], dp[col]) + triangle[row][col];
        }
    }
    answer = *max_element(dp.begin(), dp.end());
    return answer;
}