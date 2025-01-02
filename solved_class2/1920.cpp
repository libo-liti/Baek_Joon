#include <iostream>
#include <map>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    map<int, int> m;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        m[input] = 1;
    }

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int input;
        cin >> input;

        if (m.find(input) != m.end())
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}