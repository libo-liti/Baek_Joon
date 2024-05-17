#include <iostream>
using namespace std;

int main()
{
    int arr[11] = {0};
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for (int i = 4; i < 11; i++)
        arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}