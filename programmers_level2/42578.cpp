#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;
    int sum = 1;
    map<string, int> m;

    for (const auto &i : clothes)
        m[i[1]]++;

    for (const auto &i : m)
        sum *= (i.second + 1);

    answer = sum - 1;
    return answer;
}

int main()
{
    vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(clothes);
    return 0;
}