#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string LCS(string s1, string s2)
{
    s1.insert(0, " ");
    s2.insert(0, " ");
    int s1_len = s1.size(), s2_len = s2.size();
    int len = max(s1_len, s2_len);
    string answer = "";

    vector<vector<int>> v(len, vector(len, 0));

    for (int i = 1; i < s1_len; i++)
        for (int j = 1; j < s2_len; j++)
        {
            if (s1[i] == s2[j])
                v[i][j] = v[i - 1][j - 1] + 1;
            else
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
        }

    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while (v[i][j])
    {
        if (v[i][j] == v[i - 1][j])
            i--;
        else if (v[i][j] == v[i][j - 1])
            j--;
        else
        {
            answer += s1[i];
            i--;
            j--;
        }
    }
    return answer;
}

int main()
{
    string s1, s2, answer;
    cin >> s1 >> s2;
    answer = LCS(s1, s2);
    reverse(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    if (answer.size() != 0)
        cout << answer;
    return 0;
}