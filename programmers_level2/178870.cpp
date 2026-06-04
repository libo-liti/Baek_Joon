#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;
    int sum = 0;

    int dist = sequence.size() + 1;
    int leftIndex = 0;
    int rightIndex = 0;

    for (int right = 0, left = 0; right < sequence.size(); right++)
    {
        sum += sequence[right];
        while (k <= sum)
        {
            if (k == sum && right - left < dist)
            {
                leftIndex = left;
                rightIndex = right;
                dist = right - left;
            }

            sum -= sequence[left];
            left++;
        }
    }
    answer.push_back(leftIndex);
    answer.push_back(rightIndex);
    return answer;
}

int main()
{
    vector<int> sequence = {2, 2, 2, 2, 2};
    int k = 6;
    vector<int> answer = solution(sequence, k);
    cout << answer[0] << " " << answer[1];
}