#include <iostream>
using namespace std;

long long int a, b, c, tem;

long long int F(long long int bb)
{
    if (bb == 0)
        return 1;
    if (bb == 1)
        return a % c;

    tem = F(bb / 2) % c;

    if (bb % 2 == 0)
        return tem * tem % c;
    else
        return tem * tem % c * a % c;
}

int main()
{
    cin >> a >> b >> c;
    cout << F(b);
    return 0;
}