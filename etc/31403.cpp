#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b, c, tem;
    cin >> a >> b >> c;
    cout << a + b - c << endl;

    tem = to_string(b).size();
    for (int i = 0; i < tem; i++)
        a *= 10;
    cout << a + b - c;
    return 0;
}