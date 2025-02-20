#include <iostream>
#include <map>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        map<string, int> m;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if (m.find(s2) != m.end())
                m[s2]++;
            else
                m[s2] = 1;
        }

        int answer = 1;
        for (auto i : m)
            answer *= (i.second + 1);
        cout << answer - 1 << "\n";
    }
    return 0;
}