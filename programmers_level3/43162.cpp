#include <string>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>> &graph, vector<int> &visited, int n)
{
    for (auto i : graph[n])
    {
        if (!visited[i])
        {
            visited[i] = 1;
            DFS(graph, visited, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<vector<int>> graph(n);
    vector<int> visited(n, 0);

    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[0].size(); j++)
        {
            if (i == j)
                continue;

            if (computers[i][j] == 1)
                graph[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            answer++;
            visited[i] = 1;
            DFS(graph, visited, i);
        }
    }
    return answer;
}