#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> node;
set<int> visit;

void dfs(int index)
{
    for (int i = 0; i < node[index].size(); i++)
        if (!visit.count(node[index][i]))
        {
            visit.insert(node[index][i]);
            dfs(node[index][i]);
        }
    return;
}

int main()
{
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;
    node.resize(nodeNum + 1);

    while (edgeNum--)
    {
        int edge1, edge2;
        cin >> edge1 >> edge2;
        node[edge1].push_back(edge2);
        node[edge2].push_back(edge1);
    }
    dfs(1);
    visit.erase(1);
    cout << visit.size();
    return 0;
}