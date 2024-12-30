#include <iostream>
using namespace std;

int main()
{
    int n, t, p, t_n = 0, p_n = 0, p_one = 0;
    int size[6]{};
    cin >> n;
    for (int i = 0; i < 6; i++)
        cin >> size[i];

    cin >> t >> p;

    for (int i = 0; i < 6; i++)
    {
        t_n += size[i] / t;
        if (size[i] % t != 0)
            t_n++;
    }
    p_n = n / p;
    p_one = n % p;
    cout << t_n << "\n";
    cout << p_n << " " << p_one;
    return 0;
}