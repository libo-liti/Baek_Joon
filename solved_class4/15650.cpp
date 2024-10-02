#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
set<int> visited;
vector<int> v(m);

void dfs(int value, int depth)
{
    if (depth == m)
    {
        for (auto iter = v.begin(); iter != v.end(); ++iter)
            cout << *iter << " ";
        cout << "\n";
        return;
    }

    for (int i = value; i <= n; i++)
    {
        if (!visited.count(i))
        {
            visited.insert(i);
            v.push_back(i);
            dfs(i + 1, depth + 1);
            v.pop_back();
            visited.erase(i);
        }
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 0);
    return 0;
}
