#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            if (pq.empty())
                cout << 0 << "\n";
            else
            {
                cout << pq.top().first * pq.top().second << "\n";
                pq.pop();
            }
        }
        else
        {
            if (input > 0)
                pq.push({input, 1});
            else
                pq.push({-input, -1});
        }
    }
    return 0;
}