#include <iostream>
using namespace std;

int dp[1001] = {0, 1, 3};

int DP(int idx)
{
    int value;
    value = ((dp[idx - 1] % 10007) * (2 % 10007)) % 10007;

    if (idx % 2 == 0)
        value++;
    else
        value--;

    return value;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 3; i <= n; i++)
        dp[i] = DP(i);

    cout << dp[n];
    return 0;
}