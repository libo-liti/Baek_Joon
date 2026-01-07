#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int A, B, answer = -1;
    cin >> A >> B;

    queue<pair<int, int>> q;
    q.push({A, 1});

    while (!q.empty())
    {
        long long tem, value, depth;
        value = q.front().first;
        depth = q.front().second;
        q.pop();

        if (value == B)
        {
            answer = depth;
            break;
        }

        tem = value * 10 + 1;
        if (tem <= B)
            q.push({value * 10 + 1, depth + 1});
        tem = value * 2;
        if (tem <= B)
            q.push({value * 2, depth + 1});
    }
    cout << answer;
    return 0;
}