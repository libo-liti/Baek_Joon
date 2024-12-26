#include <iostream>
#include <map>
using namespace std;
const int Operand = 1000000007;

map<long long, long long> m;

long long Fibo(long long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (m.find(n) != m.end())
        return m[n];

    if (n % 2 == 0)
    {
        long long fibo = Fibo(n / 2);
        long long fibo_m1 = Fibo(n / 2 - 1);

        m[n] = (fibo * (fibo + 2 * fibo_m1)) % Operand;
        return m[n];
    }
    else
    {
        long long fibo = Fibo(n / 2);
        long long fibo_p1 = Fibo(n / 2 + 1);

        m[n] = (fibo * fibo + fibo_p1 * fibo_p1) % Operand;
        return m[n];
    }
}

int main()
{
    long long n;
    cin >> n;

    cout << Fibo(n);

    return 0;
}