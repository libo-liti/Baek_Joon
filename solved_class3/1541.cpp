#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool minusFlag = false;
    string s;
    int idx = 0, answer = 0, value;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-' || s[i] == '+')
        {
            value = stoi(s.substr(idx, i - idx));
            idx = i + 1;

            if (minusFlag)
                answer -= value;
            else
            {
                if (s[i] == '-')
                    minusFlag = true;
                answer += value;
            }
        }
    }
    value = stoi(s.substr(idx, s.size() - idx));
    if (minusFlag)
        answer -= value;
    else
        answer += value;
    cout << answer;
    return 0;
}