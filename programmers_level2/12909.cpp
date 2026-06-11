#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    int point = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            point++;
        else
        {
            if (point <= 0)
                return answer;
            point--;
        }
    }
    answer = (point == 0) ? true : false;
    return answer;
}

int main()
{
    string s = "()()()";
    solution(s);
    return 0;
}