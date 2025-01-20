#include <iostream>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int sum = 0, score = 0;
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'O')
            {
                score++;
                sum += score;
            }
            else
                score = 0;
        }
        cout << sum << endl;
    }
    return 0;
}