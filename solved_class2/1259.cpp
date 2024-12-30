#include <iostream>
using namespace std;

int main()
{
    while (true)
    {
        string s, answer = "yes";
        cin >> s;

        if (s == "0")
            break;

        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - i - 1])
            {
                answer = "no";
                break;
            }
        }
        cout << answer << "\n";
    }
}