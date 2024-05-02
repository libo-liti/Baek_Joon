#include <iostream>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int testCase, s = 0;
    cin >> testCase;

    while (testCase--)
    {
        string op;
        int x;
        cin >> op;

        if (op != "all" && op != "empty")
            cin >> x;

        if (op == "add")
            s |= 1 << x;
        else if (op == "remove")
            s &= ~(1 << x);
        else if (op == "check")
        {
            if (s & (1 << x))
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (op == "toggle")
            s ^= 1 << x;
        else if (op == "all")
            s = (1 << 21) - 1;
        else if (op == "empty")
            s = 0;
    }

    return 0;
}
