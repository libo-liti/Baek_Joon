#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, max = -4001, count;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v[i] = input;
        if (m.find(input) != m.end())
            m[input]++;
        else
            m[input] = 1;
    }
    sort(v.begin(), v.end());

    double sum = accumulate(v.begin(), v.end(), 0);
    double aver = sum / v.size();
    if (aver <= 0 && aver > -0.5)
        aver = 0;
    else
        aver = round(aver);

    for (auto i : m)
        if (i.second > max)
            max = i.second;

    vector<int> vv;
    for (auto i : m)
        if (i.second == max)
            vv.push_back(i.first);

    if (vv.size() == 1)
        count = vv[0];
    else
        count = vv[1];

    cout << aver << "\n";
    cout << v[n / 2] << "\n";
    cout << count << "\n";
    cout << v[n - 1] - v[0];
    return 0;
}