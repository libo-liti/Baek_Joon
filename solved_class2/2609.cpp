#include <iostream>
using namespace std;

int main()
{
    int a, b, x, y;
    cin >> a >> b;
    x = a;
    y = b;

    while (true)
    {
        int tem;
        tem = b;
        b = a % b;
        a = tem;

        if (b == 0)
            break;
    }

    cout << a << "\n";
    cout << x * y / a;

    return 0;
}