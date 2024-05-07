#include <iostream>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, tem;
        cin >> n;

        int a = 1, b = 0;

        for (int i = 0; i < n; i++)
        {
            tem = b;
            b = a + b;
            a = tem;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}