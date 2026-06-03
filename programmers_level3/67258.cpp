#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    map<string, int> m;

    set<string> s(gems.begin(), gems.end());
    int kinds = s.size();
    int needed = 0;

    int left = 0;
    int right = 0;

    int dist = gems.size();
    int minIndex = 0;
    int maxIndex = 0;

    if (kinds == 1)
    {
        answer.push_back(1);
        answer.push_back(1);
    }
    else
    {
        while (right < gems.size())
        {
            if (kinds != needed)
            {
                m[gems[right]]++;

                if (m[gems[right]] == 1)
                    needed++;

                if (needed == kinds)
                {
                    if (dist > right - left)
                    {
                        dist = right - left;
                        minIndex = left;
                        maxIndex = right;
                    }
                }
                else
                    right++;
            }
            else
            {
                m[gems[left]]--;
                if (m[gems[left]] == 0)
                    needed--;

                left++;

                if (needed == kinds)
                {
                    if (dist > right - left)
                    {
                        dist = right - left;
                        minIndex = left;
                        maxIndex = right;
                    }
                }
                else
                    right++;
            }
        }

        answer.push_back(minIndex + 1);
        answer.push_back(maxIndex + 1);
    }
    return answer;
}

int main()
{
    vector<string> gems = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
    vector<int> answer = solution(gems);
    cout << answer[0] << " " << answer[1];
}