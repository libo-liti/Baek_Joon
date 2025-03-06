#include <iostream>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, a, b, sum, count, _max;
    a = b = sum = count = _max = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        if (i == 0)
        {
            b = input;
            sum = count = 1;
        }
        else if (input == b)
        {
            sum++;
            count++;
        }
        else if (input == a)
        {
            int tem = a;
            a = b;
            b = tem;
            sum++;
            count = 1;
        }
        else if (input != a && input != b)
        {
            a = b;
            b = input;
            sum = count + 1;
            count = 1;
        }

        if (_max < sum)
            _max = sum;
    }
    cout << _max;
    return 0;
}