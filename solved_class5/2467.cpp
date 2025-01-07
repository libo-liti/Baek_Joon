#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;
vector<int> v;
int n1, n2, _min = INF;

void Search()
{
    int left = 0, right = v.size() - 1;

    while (right != left)
    {
        if (abs(v[right] + v[left]) < abs(_min))
        {
            n1 = v[left];
            n2 = v[right];
            _min = v[right] + v[left];
        }

        if (v[right] + v[left] > 0)
            right--;
        else
            left++;
    }
}

int main()
{
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    Search();
    cout << n1 << " " << n2;
    return 0;
}