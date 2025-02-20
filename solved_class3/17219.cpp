#include <iostream>
#include <map>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    map<string, string> _map;

    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        _map[s1] = s2;
    }

    for (int i = 0; i < m; i++)
    {
        string s1;
        cin >> s1;
        cout << _map[s1] << "\n";
    }
    return 0;
}