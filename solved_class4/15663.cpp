#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m, input;
vector<int> answer;
vector<int> v;
set<int> s;
set<int> visited;

void dfs(int depth)
{
    if (depth == m)
    {
        for (auto i : answer)
            cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0)
            if (v[i - 1] == v[i] && !visited.count(i - 1))
                continue;

        if (!visited.count(i))
        {
            visited.insert(i);
            answer.push_back(v[i]);
            dfs(depth + 1);
            answer.pop_back();
            visited.erase(i);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    dfs(0);
}