#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;
    int s1_len, s2_len;
    cin >> s1 >> s2;

    // arr배열을 (1,1)부터 시작하기 위해
    s1.insert(0, " ");
    s2.insert(0, " ");

    s1_len = s1.length();
    s2_len = s2.length();

    // 배열 할당 및 초기화
    int **arr = new int *[s1_len];
    for (int i = 0; i < s1_len; i++)
    {
        arr[i] = new int[s2_len];
        fill(arr[i], arr[i] + s2_len, 0);
    }

    // 두 수열 비교
    for (int i = 1; i < s1_len; i++)
    {
        for (int j = 1; j < s2_len; j++)
        {
            if (s1[i] == s2[j]) // 글자가 같으면 이전까지 최대 수열 + 1
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else // 글자가 다르면 이전까지 최대 수열
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }

    // 결과 출력
    cout << arr[s1_len - 1][s2_len - 1];

    // 메모리 해제
    for (int i = 0; i < s1_len; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}