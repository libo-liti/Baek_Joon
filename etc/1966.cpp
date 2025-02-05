#include <iostream>
#include <queue>
using namespace std;

void PrintQ(int n, int m)
{
    int idx = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        pq.push({input, i});
        q.push({input, i});
    }

    while (true)
    {
        int _max = pq.top().first;
        pq.pop();

        while (true)
        {
            int i = q.front().first;
            int s = q.front().second;
            q.pop();

            if (_max == i)
            {
                if (s == m)
                {
                    cout << idx << "\n";
                    return;
                }
                else
                    break;
            }
            q.push({i, s});
        }
        idx++;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, m, idx = 1;
        cin >> n >> m;
        PrintQ(n, m);
    }
    return 0;
}