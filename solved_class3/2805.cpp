#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int treeNum, needTree, first, mid, end, answer = -1;
    long long sum = 0;
    vector<int> v;
    cin >> treeNum >> needTree;

    v.resize(treeNum, 0);

    for (int i = 0; i < v.size(); i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    first = 0;
    end = v.back();

    while (first <= end)
    {
        mid = (first + end) / 2;
        sum = 0;

        for (int i = 0; i < treeNum; i++)
            if (v[i] > mid)
                sum += v[i] - mid;

        if (sum == needTree)
        {
            answer = mid;
            break;
        }
        else if (sum > needTree)
        {
            first = mid + 1;
            if (answer < mid)
                answer = mid;
        }
        else if (sum < needTree)
            end = mid - 1;
    }
    cout << answer;
    return 0;
}