#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            int plus = numbers[i] + numbers[j];
            if (find(answer.begin(), answer.end(), plus) == answer.end())
                answer.push_back(plus);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> numbers = {5, 0, 2, 7};
    for (auto i : solution(numbers))
        cout << i << " ";
}