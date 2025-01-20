#include <iostream>
using namespace std;

int main()
{
    int arr[8];
    string s = "mixed";

    for (int i = 0; i < 8; i++)
        cin >> arr[i];

    for (int i = 2; i < 8; i++)
    {
        if (arr[i - 1] - arr[i - 2] != arr[i] - arr[i - 1])
            break;
        if (i == 7)
        {
            if (arr[7] == 8)
                s = "ascending";
            else
                s = "descending";
        }
    }
    cout << s;
    return 0;
}