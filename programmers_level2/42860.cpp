#include <string>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int answer = 0;

    // 세로 이동
    for (int i = 0; i < name.size(); i++)
    {
        int down = name[i] - 'A';
        int up = 'Z' - name[i] + 1;
        answer += min(down, up);
    }

    // 가로 이동
    int width = name.size() - 1;
    for (int i = 0; i < name.size(); i++)
    {
        int next = i + 1;
        while (next < name.size() && name[next] == 'A')
            next++;

        int back = i * 2 + (name.size() - next);
        int back2 = (name.size() - next) * 2 + i;

        width = min(width, min(back, back2));
    }
    answer += width;

    return answer;
}