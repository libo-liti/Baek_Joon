#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, s, _min;

void Search()
{
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        if (i == 0)
            v[i] = input;
        else
            v[i] = v[i - 1] + input;

        if (v[i] >= s)
            _min = min(_min, i + 1);
    }
    if (_min == 1)
        return;

    int index = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = index; j < n; j++)
        {
            if (v[j] - v[i] >= s)
            {
                index = j;
                _min = min(_min, j - i);
                if (_min == 1)
                    return;
                break;
            }
            if (j == n - 1)
                return;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> s;
    v.resize(n);

    _min = n + 1;

    Search();

    if (_min == n + 1)
        cout << 0;
    else
        cout << _min;

    return 0;
}