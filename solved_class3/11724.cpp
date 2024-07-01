#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> node;
set<int> visit;
int connectComponent;

void dfs(int index)
{
    // 방문 하지 않았으면 방문하기
    if (!visit.count(index))
    {
        visit.insert(index);
        // 노드에 연결된 간선들 모두 방문하기
        for (int i = 0; i < node[index].size(); i++)
            dfs(node[index][i]);
    }
    return;
}

int main()
{
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;

    node.resize(nodeNum + 1);

    // 그래프 생성
    for (int i = 0; i < edgeNum; i++)
    {
        int edge1, edge2;
        cin >> edge1 >> edge2;

        node[edge1].push_back(edge2);
        node[edge2].push_back(edge1);
    }

    // dfs 들어가기 전과 들어난 후에 visit의 개수가 다르다면 연결요소가 하나 증가
    for (int i = 1; i <= nodeNum; i++)
    {
        int tem = visit.size();
        dfs(i);
        if (tem != visit.size())
            connectComponent++;
    }
    cout << connectComponent;
    return 0;
}