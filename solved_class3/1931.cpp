#include <iostream>
#include <algorithm>
using namespace std;

// 회의 시간 구조체
struct Meeting
{
    int startTime, endTime;
} m[100001];

// 구조체 정렬 함수
// 끝 시간을 기준으로 정렬, 끝 시간이 같은 경우 시작시간 비교
int compare(const Meeting &a, const Meeting &b)
{
    if (a.endTime == b.endTime)
        return a.startTime < b.startTime;
    return a.endTime < b.endTime;
}

int main()
{
    int num, previousEndTime, count = 1;
    cin >> num;

    // 시작시간, 끝 시간 입력
    for (int i = 0; i < num; i++)
        cin >> m[i].startTime >> m[i].endTime;

    // 끝 시간 기준 정렬
    sort(m, m + num, compare);

    // 첫 회의 끝시간
    previousEndTime = m[0].endTime;

    for (int i = 1; i < num; i++)
    {
        // 이전 회의 끝시간 <= 다음 회의 시작시간
        if (previousEndTime <= m[i].startTime)
        {
            count++;
            previousEndTime = m[i].endTime;
        }
    }
    cout << count;
    return 0;
}