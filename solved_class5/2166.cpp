#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Pos
{
    double x;
    double y;
};

double area(Pos v1, Pos v2, Pos v3)
{
    return ((v2.x - v1.x) * (v3.y - v1.y) - (v3.x - v1.x) * (v2.y - v1.y)) / 2;
}

int main()
{
    int n;
    double sum;
    cin >> n;

    vector<Pos> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y;

        if (i == 0 || i == 1)
            continue;

        sum += area(v[0], v[i - 1], v[i]);
    }
    cout << fixed;
    cout.precision(1);
    cout << fabs(sum);
    return 0;
}