#include <string>
#include <vector>
#include <iostream>

using namespace std;

int DFS(vector<int> &numbers, int target, int depth, int sum)
{
    if (depth == numbers.size())
    {
        if (sum == target)
            return 1;
        else
            return 0;
    }

    return DFS(numbers, target, depth + 1, sum + numbers[depth]) + DFS(numbers, target, depth + 1, sum - numbers[depth]);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    answer = DFS(numbers, target, 0, 0);
    return answer;
}

int main()
{
    vector<int> numbers = {4, 1, 2, 1};
    int target = 4;

    cout << solution(numbers, target);
}