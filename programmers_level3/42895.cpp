#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number)
{
    int answer = -1;
    vector<set<int>> dp(9);
    char n = '0' + N;
    string s = "";

    for (int k = 1; k < 9; k++)
    {
        s += n;
        int value = stoi(s);
        dp[k].insert(value);

        for (int i = 1; i < k; i++)
        {
            for (auto a : dp[i])
            {
                for (auto b : dp[k - i])
                {
                    dp[k].insert(a + b);
                    dp[k].insert(a - b);
                    dp[k].insert(a * b);
                    if (b != 0)
                        dp[k].insert(a / b);
                }
            }
        }
        if (dp[k].count(number))
            return k;
    }

    return answer;
}