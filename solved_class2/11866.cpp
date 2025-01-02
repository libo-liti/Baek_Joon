#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k, pos = 0;
    cin >> n >> k;

    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    k--;

    cout << "<";
    while (v.size() != 1)
    {
        pos += k;
        while (pos >= v.size())
            pos -= v.size();
        cout << v[pos] << ", ";
        v.erase(v.begin() + pos);
    }
    cout << v[0] << ">";
    return 0;
}