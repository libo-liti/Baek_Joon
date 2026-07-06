#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool IsOneCharDiff(string a, string b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            cnt++;
        if (cnt > 1)
            return false;
    }
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    if (find(words.begin(), words.end(), target) == words.end())
        return answer;

    queue<pair<string, int>> q;
    unordered_set<string> visited;
    q.push({begin, 0});
    visited.insert(begin);

    while (!q.empty())
    {
        auto [word, depth] = q.front();
        q.pop();

        if (word == target)
        {
            answer = depth;
            break;
        }

        for (auto i : words)
        {
            if (IsOneCharDiff(word, i) && visited.find(i) == visited.end())
            {
                visited.insert(i);
                q.push({i, depth + 1});
            }
        }
    }

    return answer;
}