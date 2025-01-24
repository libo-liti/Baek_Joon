#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, _remove;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    _remove = round(n * 0.15);
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    v.erase(v.begin(), v.begin() + _remove);
    v.erase(v.end() - _remove, v.end());

    double sum = 0;
    double aver;

    for (auto i : v)
        sum += i;
    aver = round(sum / v.size());
    cout << aver;
    return 0;
}