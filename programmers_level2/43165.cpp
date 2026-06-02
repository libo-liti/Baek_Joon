#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    int sum = 0;
    stack<pair<int, int>> s;
    s.push({0, 0});

    while (!s.empty())
    {
        int depth = s.top().first;
        int sum = s.top().second;
        s.pop();

        if (depth == numbers.size())
        {
            if (sum == target)
                answer++;
        }
        else
        {
            s.push({depth + 1, sum + numbers[depth]});
            s.push({depth + 1, sum - numbers[depth]});
        }
    }
    return answer;
}

int main()
{
    vector<int> numbers = {4, 1, 2, 1};
    int target = 4;

    cout << solution(numbers, target);
    return 0;
}