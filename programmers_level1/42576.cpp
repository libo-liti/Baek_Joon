#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    map<string, int> m;
    for (const auto &i : participant)
        m[i]++;

    for (auto &i : completion)
    {
        if (m.find(i) != m.end())
            m[i]--;
    }

    for (auto i : m)
        if (i.second == 1)
            answer = i.first;

    return answer;
}