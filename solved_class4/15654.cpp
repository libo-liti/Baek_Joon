#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> result;
set<int> visited;
int n, m;

void dfs(int depth)
{
    if (depth == m)
    {
        for (auto i : result)
            cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited.count(v[i]))
        {
            visited.insert(v[i]);
            result.push_back(v[i]);
            dfs(depth + 1);
            result.pop_back();
            visited.erase(v[i]);
        }
    }
}

int main()
{
    cin >> n >> m;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    dfs(0);
    return 0;
}