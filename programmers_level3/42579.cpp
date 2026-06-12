#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> m;
    priority_queue<pair<int, string>> pq;
    unordered_map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>> ranking;
    for (int i = 0; i < genres.size(); i++)
    {
        m[genres[i]] += plays[i];
        ranking[genres[i]].push({plays[i], i});
    }

    for (const auto &i : m)
        pq.push({i.second, i.first});

    while (!pq.empty())
    {
        string genre = pq.top().second;
        pq.pop();

        for (int i = 0; i < 2; i++)
        {
            if (ranking[genre].empty())
                continue;

            int index = ranking[genre].top().second;
            answer.push_back(index);
            ranking[genre].pop();
        }
    }

    return answer;
}