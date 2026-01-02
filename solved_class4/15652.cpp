#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, value;
    cin >> n >> m;

    vector<int> v(m, 1);
    auto iter = v.end() - 1;
    for (auto i : v)
        cout << i << " ";
    cout << "\n";

    while (true)
    {
        if (*iter == n)
            iter--;
        else
        {
            (*iter)++;
            value = *iter;
            while (iter != v.end() - 1)
            {
                *iter = value;
                iter++;
            }
            *iter = value;

            for (auto i : v)
                cout << i << " ";
            cout << "\n";
        }

        if (v.front() == n)
            break;
    }
    return 0;
}