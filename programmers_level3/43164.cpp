#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<string>> graph;
map<pair<string, string>, int> ticket;
int number, cnt;

void DFS(string startPos, vector<string> &answer)
{
    answer.push_back(startPos);
    if (cnt == number)
        return;

    for (auto endPos : graph[startPos])
    {
        if (ticket[{startPos, endPos}] > 0)
        {
            ticket[{startPos, endPos}]--;
            cnt++;
            DFS(endPos, answer);

            if (cnt == number)
                return;

            cnt--;
            ticket[{startPos, endPos}]++;
        }
    }
    answer.pop_back();
    return;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    number = tickets.size();

    for (int i = 0; i < tickets.size(); i++)
    {
        graph[tickets[i][0]].push_back(tickets[i][1]);
        ticket[{tickets[i][0], tickets[i][1]}]++;
    }

    for (auto &i : graph)
        sort(i.second.begin(), i.second.end());

    DFS("ICN", answer);

    return answer;
}