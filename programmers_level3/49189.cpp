#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    int maxDepth = 0;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    map<int, int> m;

    for (int i = 0; i < edge.size(); i++)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    q.push({1, 0});
    visited[1] = true;

    while (!q.empty())
    {
        auto [node, depth] = q.front();
        q.pop();

        for (auto &next : graph[node])
        {
            if (!visited[next])
            {
                q.push({next, depth + 1});
                visited[next] = true;
                m[depth]++;

                if (maxDepth < depth)
                    maxDepth = depth;
            }
        }
    }
    answer = m[maxDepth];
    return answer;
}