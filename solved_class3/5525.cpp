#include <iostream>
using namespace std;

int main()
{
    int n, len, flag = false, cnt = 0, answer = 0;
    string input;

    cin >> n >> len >> input;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'I')
        {
            if (flag == true && input[i - 1] == 'O')
            {
                cnt++;
                if (n == cnt)
                {
                    answer++;
                    cnt--;
                }
            }
            else
            {
                flag = true;
                cnt = 0;
            }
        }
        else if (input[i] == 'O')
        {
            if (flag && input[i - 1] != 'I')
                flag = false;
        }
    }
    cout << answer;
    return 0;
}