#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> m;

    for (const auto &i : nums)
        m[i]++;

    answer = m.size() < nums.size() / 2 ? m.size() : nums.size() / 2;
    return answer;
}

int main()
{
    vector<int> nums = {3, 3, 3, 2, 2, 4};
    cout << solution(nums);
}