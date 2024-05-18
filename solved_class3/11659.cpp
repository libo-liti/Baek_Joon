#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int num, testCase;
    cin >> num >> testCase;
    vector<int> vec(num + 1);
    vec[0] = 0;

    for (int i = 1; i <= num; i++)
    {
        int n;
        cin >> n;
        vec[i] = vec[i - 1] + n;
    }

    while (testCase--)
    {
        int a, b;
        cin >> a >> b;
        cout << vec[b] - vec[a - 1] << "\n";
    }
    return 0;
}