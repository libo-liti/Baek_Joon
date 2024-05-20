#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1, 1);

    for (int i = 2; i <= n; i++)
        v[i] = (v[i - 2] + v[i - 1]) % 10007;
    cout << v[n];
    return 0;
}