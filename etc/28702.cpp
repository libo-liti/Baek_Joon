#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string F = "Fizz", B = "Buzz", FB = "FizzBuzz";
    for (int i = 0; i < 3; i++)
    {
        string s;
        cin >> s;
        if (s != F && s != B && s != FB)
            n = stoi(s) + (3 - i);
    }

    if (n % 3 == 0 && n % 5 == 0)
        cout << FB;
    else if (n % 3 == 0)
        cout << F;
    else if (n % 5 == 0)
        cout << B;
    else
        cout << n;
    return 0;
}