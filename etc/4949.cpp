#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    while (true)
    {
        stack<char> s;
        string str, answer = "yes";
        getline(cin, str);

        if (str == ".")
            break;

        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];
            if (c == '(')
                s.push('(');
            else if (c == '[')
                s.push('[');
            else if (c == ')')
            {
                if (s.empty() || s.top() != '(')
                {
                    answer = "no";
                    break;
                }
                else
                    s.pop();
            }
            else if (c == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    answer = "no";
                    break;
                }
                else
                    s.pop();
            }
        }
        if (!s.empty())
            answer = "no";
        cout << answer << "\n";
    }
    return 0;
}