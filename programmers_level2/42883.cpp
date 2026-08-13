#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    for (auto c : number)
    {
        while (k > 0 && !answer.empty() && answer.back() < c)
        {
            answer.pop_back();
            k--;
        }
        answer.push_back(c);
    }

    for (int i = 0; i < k; i++)
        answer.pop_back();

    return answer;
}