#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int count = 0;
    int day = 1;

    for (int i = 0; i < progresses.size(); i++)
    {
        progresses[i] += speeds[i] * day;

        if (progresses[i] >= 100)
            count++;
        else
        {
            if (i != 0)
                answer.push_back(count);
            count = 0;

            while (progresses[i] < 100)
            {
                day++;

                progresses[i] += speeds[i];
            }

            count++;
        }
    }
    answer.push_back(count);
    return answer;
}

int main()
{
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};
    solution(progresses, speeds);
    return 0;
}