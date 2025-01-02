#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string str, answer = "NO";
        stack<char> s;
        cin >> str;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
                s.push('(');
            else
            {
                if (s.empty())
                    break;

                s.pop();
            }
            if (i == str.size() - 1)
            {
                if (s.empty())
                    answer = "YES";
            }
        }
        cout << answer << "\n";
    }
    return 0;
}