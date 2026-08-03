#include <string>
#include <vector>

using namespace std;

int DFS(vector<vector<int>> &graph, int node, vector<bool> &visited)
{
    int cnt = 1;
    visited[node] = true;
    for (auto &i : graph[node])
    {
        if (!visited[i])
            cnt += DFS(graph, i, visited);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    vector<vector<int>> front(n + 1);
    vector<vector<int>> back(n + 1);

    for (int i = 0; i < results.size(); i++)
    {
        front[results[i][1]].push_back(results[i][0]);
        back[results[i][0]].push_back(results[i][1]);
    }

    for (int i = 1; i <= n; i++)
    {
        vector<bool> frontVisited(n + 1, false);
        vector<bool> backVisited(n + 1, false);

        if (DFS(front, i, frontVisited) + DFS(back, i, backVisited) - 1 == n)
            answer++;
    }

    return answer;
}