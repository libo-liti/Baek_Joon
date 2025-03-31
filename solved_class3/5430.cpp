#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

void AC()
{
    vector<int> v;
    string func, input, num, n;
    cin >> func >> n >> input;

    // input string -> int
    for (auto c : input)
    {
        if (isdigit(c))
            num += c;
        else if (!num.empty())
        {
            v.push_back(stoi(num));
            num.clear();
        }
    }

    int front = 0;
    int end = v.size() - 1;
    bool reverse = false;

    for (int i = 0; i < func.size(); i++)
    {
        if (func[i] == 'R')
            reverse = !reverse;
        else
        {
            // empty
            if (front > end)
            {
                cout << "error" << "\n";
                return;
            }

            if (!reverse)
                front++;
            else
                end--;
        }
    }

    if (!reverse)
    {
        cout << "[";
        if (front <= end)
            cout << v[front++];
        for (; front <= end; front++)
            cout << "," << v[front];
    }
    else
    {
        cout << "[";
        if (front <= end)
            cout << v[end--];
        for (; front <= end; end--)
            cout << "," << v[end];
    }
    cout << "]\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int testCase;
    cin >> testCase;

    while (testCase--)
        AC();
    return 0;
}