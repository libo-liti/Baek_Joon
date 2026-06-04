#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    set<string> s(gems.begin(), gems.end());
    int kinds = s.size();
    int needed = 0;

    int dist = gems.size();
    int leftIndex = 0;
    int rightIndex = 0;

    map<string, int> m;

    for (int right = 0, left = 0; right < gems.size(); right++)
    {
        m[gems[right]]++;
        if (m[gems[right]] == 1)
            needed++;

        while (needed == kinds)
        {
            if (right - left < dist)
            {
                dist = right - left;
                leftIndex = left;
                rightIndex = right;
            }

            m[gems[left]]--;
            if (m[gems[left]] == 0)
                needed--;
            left++;
        }
    }

    answer.push_back(leftIndex + 1);
    answer.push_back(rightIndex + 1);
    return answer;
}

int main()
{
    vector<string> gems = {"XYZ", "XYZ", "XYZ"};
    vector<int> answer = solution(gems);
    cout << answer[0] << " " << answer[1];
}