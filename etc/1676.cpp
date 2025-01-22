#include <iostream>
using namespace std;

int main()
{
    int n, zero = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tem = i;
        while (tem % 5 == 0)
        {
            zero++;
            tem /= 5;
        }
    }
    cout << zero;
    return 0;
}