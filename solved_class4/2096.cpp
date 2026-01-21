#include <iostream>
using namespace std;

int CompareMax(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    return c;
}

int CompareMin(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    return c;
}

int main()
{
    int n;
    cin >> n;

    int dp_max[3];
    int dp_min[3];
    int tem_max[3];
    int tem_min[3];

    int a, b, c;
    cin >> a >> b >> c;
    dp_max[0] = dp_min[0] = a;
    dp_max[1] = dp_min[1] = b;
    dp_max[2] = dp_min[2] = c;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;

        // 1번
        tem_max[0] = max(dp_max[0], dp_max[1]) + a;
        tem_min[0] = min(dp_min[0], dp_min[1]) + a;

        // 2번
        tem_max[1] = CompareMax(dp_max[0], dp_max[1], dp_max[2]) + b;
        tem_min[1] = CompareMin(dp_min[0], dp_min[1], dp_min[2]) + b;

        // 3번
        tem_max[2] = max(dp_max[1], dp_max[2]) + c;
        tem_min[2] = min(dp_min[1], dp_min[2]) + c;

        for (int j = 0; j < 3; j++)
        {
            dp_max[j] = tem_max[j];
            dp_min[j] = tem_min[j];
        }
    }
    cout << CompareMax(dp_max[0], dp_max[1], dp_max[2]) << " "
         << CompareMin(dp_min[0], dp_min[1], dp_min[2]);

    return 0;
}