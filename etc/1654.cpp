#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k, n, answer, max;
vector<int> v;

int Search(int n)
{
    long long sum = 0;
    for (auto i : v)
        sum += i / n;
    return sum;
}

int main()
{
    cin >> k >> n;
    v.resize(k, 0);
    for (int i = 0; i < k; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    long long start = 1, mid, end = v[k - 1];
    while (start <= end)
    {
        mid = (start + end) / 2;
        int num = Search(mid);

        if (num >= n)
        {
            start = mid + 1;
            if (answer < mid)
                answer = mid;
        }
        else
            end = mid - 1;
    }
    cout << answer;
    return 0;
}