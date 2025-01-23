#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, sum = 0;
    cin >> k;
    vector<int> v;

    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        if (n == 0)
            v.pop_back();
        else
            v.push_back(n);
    }
    for (auto i : v)
        sum += i;
    cout << sum;
    return 0;
}