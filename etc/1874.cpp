#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, idx = 0;
    cin >> n;
    vector<int> v(n);
    vector<char> c;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    stack<int> s;

    for (int i = 1; i <= n; i++)
    {
        s.push(i);
        c.push_back('+');
        while (s.top() == v[idx])
        {
            s.pop();
            idx++;
            c.push_back('-');
            if (s.empty())
                break;
        }
    }
    if (s.empty())
        for (auto i : c)
            cout << i << "\n";
    else
        cout << "NO";
    return 0;
}