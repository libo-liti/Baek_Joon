#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, answer = 1;
    cin >> n;

    int *arr = new int[n];
    int *dp = new int[n];

    fill_n(dp, n, 1);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    answer = *max_element(dp, dp + n);
    cout << answer;
    return 0;
}