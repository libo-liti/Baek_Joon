#include <iostream>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int h, w, n, floor, number = 1;
        cin >> h >> w >> n;

        while (h < n)
        {
            n -= h;
            number++;
        }

        floor = n;
        cout << n;
        if (number < 10)
            cout << 0;
        cout << number << endl;
    }
    return 0;
}