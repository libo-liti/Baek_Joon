#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

set<int> visited;
int max_dist, last_node;

void DFS(vector<vector<pair<int, int>>> &v, int _dist, int _node)
{
    // 방문
    visited.insert(_node);

    // 최대거리 갱신
    if (_dist > max_dist)
    {
        max_dist = _dist;
        last_node = _node;
    }

    for (int i = 0; i < v[_node].size(); i++)
    {
        int next_node = v[_node][i].first;
        int next_dist = v[_node][i].second;

        // 방문 안했다면
        if (!visited.count(next_node))
            DFS(v, _dist + next_dist, next_node);
    }
    visited.erase(_node);
}

int main()
{
    int node_num;
    cin >> node_num;

    vector<vector<pair<int, int>>> tree(node_num + 1);

    // 입력값
    for (int i = 0; i < node_num - 1; i++)
    {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        tree[v1].push_back({v2, dist});
        tree[v2].push_back({v1, dist});
    }
    DFS(tree, 0, 1);
    max_dist = 0;
    DFS(tree, 0, last_node);
    cout << max_dist;
    return 0;
}
// 트리의 지름
// 트리에서 임의의 정점 x를 잡는다.
// 정점 x에서 가장 먼 정점 y를 찾는다.
// 정점 y에서 가장 먼 정점 z를 찾는다.