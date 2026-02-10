#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int minChikenDist = 100000000;
vector<vector<int>> graph;
vector<pair<int, int>> houses;
vector<pair<int, int>> stores;

vector<int> selectStoresIndex;

void Calculation()
{
    vector<pair<int, int>> candi;
    int sumDist = 0;

    for (auto index : selectStoresIndex)
        candi.push_back((stores[index]));

    for (auto house : houses)
    {
        int minDist = 100000000;
        for (auto store : candi)
        {
            int dist = abs(house.first - store.first) + abs(house.second - store.second);
            minDist = min(minDist, dist);
        }
        sumDist += minDist;

        if (minChikenDist < sumDist)
            return;
    }

    if (sumDist < minChikenDist)
        minChikenDist = sumDist;
}

void DFS(int depth, int node)
{
    if (depth == m)
    {
        Calculation();
        return;
    }

    for (int i = node; i < stores.size(); i++)
    {
        selectStoresIndex.push_back(i);
        DFS(depth + 1, i + 1);
        selectStoresIndex.pop_back();
    }
}

int main()
{
    cin >> n >> m;

    graph.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;

            if (input == 1)
                houses.push_back({i, j});
            else if (input == 2)
                stores.push_back({i, j});
        }
    DFS(0, 0);
    cout << minChikenDist;
    return 0;
}