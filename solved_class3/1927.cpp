#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            if (pq.empty())
                cout << 0 << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(n);
    }
    return 0;
}