#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        queue<int> q;
        string str[10000]{};
        int a, b;

        cin >> a >> b;
        q.push(a);

        while (str[b] == "")
        {
            int d, s, l, r;
            int n = q.front();
            q.pop();

            d = n * 2 % 10000;
            if (str[d] == "" && n != 0)
            {
                str[d] = str[n] + 'D';
                q.push(d);
            }

            s = (n - 1 >= 0) ? n - 1 : 9999;
            if (str[s] == "")
            {
                str[s] = str[n] + 'S';
                q.push(s);
            }

            l = n % 1000 * 10 + n / 1000;
            if (str[l] == "")
            {
                str[l] = str[n] + 'L';
                q.push(l);
            }

            r = n % 10 * 1000 + n / 10;
            if (str[r] == "")
            {
                str[r] = str[n] + 'R';
                q.push(r);
            }
        }
        cout << str[b] << "\n";
    }
    return 0;
}