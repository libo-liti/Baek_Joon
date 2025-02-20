#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (k >= v[i])
        {
            sum += k / v[i];
            k %= v[i];
        }
    }
    cout << sum;
    return 0;
}