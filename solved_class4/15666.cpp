#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
vector<int> v;
vector<int> output;
set<int> s;

void DFS(int depth, int index)
{
    if (depth == m)
    {
        for (auto i : output)
            cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = index; i < v.size(); i++)
    {
        output[depth] = v[i];
        DFS(depth + 1, i);
    }
}

int main()
{
    cin >> n >> m;
    output.resize(m);

    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        s.insert(tem);
    }

    v.assign(s.begin(), s.end());
    DFS(0, 0);

    return 0;
}