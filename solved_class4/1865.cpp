#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int INF = 10000000;

struct Edges
{
    int s, e, t;
};

bool bf(int n, vector<Edges> &v)
{
    vector<int> dist(n + 1, INF);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int s, e, t;
            s = v[j].s;
            e = v[j].e;
            t = v[j].t;

            if (dist[e] > dist[s] + t)
            {
                dist[e] = dist[s] + t;
                if (i == n)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, m, w;
        cin >> n >> m >> w;

        vector<Edges> edges;

        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        if (bf(n, edges))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}