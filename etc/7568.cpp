#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (v[i].first < v[j].first && v[i].second < v[j].second)
                num++;
        }
        cout << num + 1 << " ";
    }
    return 0;
}