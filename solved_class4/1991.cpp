#include <iostream>
using namespace std;

int tree[91][2];

void PreOrder(int node)
{
    cout << (char)node;
    for (int i = 0; i < 2; i++)
    {
        if (tree[node][i] != 46)
            PreOrder(tree[node][i]);
    }
    return;
}

void InOrder(int node)
{
    for (int i = 0; i < 2; i++)
    {
        if (tree[node][i] != 46)
            InOrder(tree[node][i]);
        if (i == 0)
            cout << (char)node;
    }
    return;
}

void PostOrder(int node)
{
    for (int i = 0; i < 2; i++)
    {
        if (tree[node][i] != 46)
            PostOrder(tree[node][i]);
    }
    cout << (char)node;
    return;
}

int main()
{
    int n;
    char node, left, right;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> node >> left >> right;
        tree[(int)node][0] = (int)left;
        tree[(int)node][1] = (int)right;
    }
    PreOrder(65);
    cout << "\n";
    InOrder(65);
    cout << "\n";
    PostOrder(65);
    return 0;
}