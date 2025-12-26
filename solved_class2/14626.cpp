#include <iostream>
using namespace std;

int main()
{
    string input;
    int sum = 0, check, mul, result;
    cin >> input;
    check = input[12] - '0';

    for (int i = 0; i < input.length() - 1; i++)
    {
        if (i % 2 == 0)
        {
            if (input[i] != '*')
                sum += (input[i] - '0');
            else
                mul = 1;
        }
        else
        {
            if (input[i] != '*')
                sum += (input[i] - '0') * 3;
            else
                mul = 3;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (((sum + mul * i) + check) % 10 == 0)
        {
            result = i;
            break;
        }
    }
    cout << result;
    return 0;
}