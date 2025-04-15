#include <iostream>
#include <map>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n;
        cin >> n;
        map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            char comand;
            int value;
            cin >> comand >> value;

            if (comand == 'I')
            {
                if (m.find(value) != m.end())
                    m[value]++;
                else
                    m[value] = 1;
            }
            else // comand == 'D'
            {
                if (m.empty())
                    continue;

                if (value == 1)
                {
                    if (m.rbegin()->second == 1)
                        m.erase(next(m.rbegin()).base());
                    else
                        m[m.rbegin()->first]--;
                }
                else // value == -1
                {
                    if (m.begin()->second == 1)
                        m.erase(m.begin());
                    else
                        m[m.begin()->first]--;
                }
            }
        }
        if (m.empty())
            cout << "EMPTY" << "\n";
        else
            cout << m.rbegin()->first << " " << m.begin()->first << "\n";
    }
    return 0;
}