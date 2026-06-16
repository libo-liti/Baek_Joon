#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string solution(vector<int> numbers)
{
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    for (auto &i : numbers)
        answer += to_string(i);
    if (answer[0] == '0')
        return "0";
    return answer;
}