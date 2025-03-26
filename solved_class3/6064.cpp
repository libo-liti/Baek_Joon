#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int m, n, x, y, currentX = 1, currentY = 1, cnt = 1;
        cin >> m >> n >> x >> y;

        int delta = x - 1;
        cnt += delta;
        currentY += delta;
        while (currentY > n)
            currentY -= n;

        for (int i = 0; i < n; i++)
        {
            if (currentY == y)
                break;

            int d = m - n;
            currentY += d;

            while (currentY <= 0)
                currentY += n;
            while (currentY > n)
                currentY -= n;
            cnt += m;

            if (i == n - 1)
                cnt = -1;
        }
        cout << cnt << "\n";
    }
    return 0;
}