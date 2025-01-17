#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

int n;
long long _min = LLONG_MAX;
vector<int> v;
vector<int> answer(3);

void Search()
{
    for (int i = 0; i < n - 2; i++)
    {
        long long value, start, end, sum;
        value = v[i];
        start = i + 1;
        end = n - 1;

        while (start < end)
        {
            sum = value + v[start] + v[end];
            if (abs(_min) > abs(sum))
            {
                answer[0] = value;
                answer[1] = v[start];
                answer[2] = v[end];
                _min = sum;
            }

            if (sum == 0)
                return;
            else if (sum < 0)
                start++;
            else
                end--;
        }
    }
}

int main()
{
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    Search();
    for (int i = 0; i < 3; i++)
        cout << answer[i] << " ";
    return 0;
}