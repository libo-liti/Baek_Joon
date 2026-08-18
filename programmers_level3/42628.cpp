#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    multiset<int> s;

    for (const auto &cmd : operations)
    {
        istringstream iss(cmd);
        string op;
        int num;

        iss >> op >> num;

        if (op == "I")
        {
            s.insert(num);
        }
        else if (!s.empty())
        {
            if (num == 1)
                s.erase(prev(s.end()));
            else if (num == -1)
                s.erase(s.begin());
        }
    }

    if (s.empty())
        return {0, 0};

    return {*s.rbegin(), *s.begin()};
}