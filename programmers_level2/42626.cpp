#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (auto i : scoville)
        pq.push(i);

    while (pq.size() >= 2 && pq.top() < K)
    {
        long long least = pq.top();
        pq.pop();

        long long secondLeast = pq.top();
        pq.pop();

        long long mixed = least + secondLeast * 2;
        pq.push(mixed);

        answer++;
    }

    return pq.top() >= K ? answer : -1;
}