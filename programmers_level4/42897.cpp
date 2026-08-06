#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money)
{
    int answer = 0;
    int n = money.size();
    vector<int> dp0(n - 1, 0);
    vector<int> dp1(n - 1, 0);

    dp0[0] = money[0];
    dp0[1] = max(money[0], money[1]);

    dp1[0] = money[1];
    dp1[1] = max(money[1], money[2]);

    for (int i = 2; i < n - 1; i++)
    {
        dp0[i] = max(dp0[i - 1], dp0[i - 2] + money[i]);
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i + 1]);
    }

    answer = max(dp0.back(), dp1.back());

    return answer;
}