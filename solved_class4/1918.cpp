#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    stack<char> s;

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            while (s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if (c == '*' || c == '/')
        {
            if (s.empty())
                s.push(c);
            else
            {
                while (!s.empty())
                {
                    if (s.top() == '+' || s.top() == '-' || s.top() == '(')
                        break;
                    cout << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else if (c == '+' || c == '-')
        {
            if (s.empty())
                s.push(c);
            else
            {
                while (!s.empty())
                {
                    if (s.top() == '(')
                        break;
                    cout << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else
            cout << c;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}