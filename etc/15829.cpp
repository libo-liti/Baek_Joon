#include <iostream>
#include <cmath>
using namespace std;
const long long Oper = 1234567891;

int main()
{
    long long arr[50];
    long long sum = 0;
    arr[0] = 1;
    int n;
    string s;
    cin >> n >> s;

    for (int i = 1; i < 50; i++)
        arr[i] = (arr[i - 1] % Oper * 31) % Oper;

    for (int i = 0; i < n; i++)
        sum = (sum % Oper + ((s[i] - 96) * arr[i]) % Oper) % Oper;
    cout << sum;
    return 0;
}