#include <math.h>

int isOneRecursive(int n, long long pos)
{
    long long areaSize;
    long long area3Left;
    long long area3Right;

    if (n == 1)
        return pos != 3;
    if ((pos + 4) % 5 == 2)
        return 0;
    areaSize = (long long)pow(5, n - 1);
    area3Left = areaSize * 2 + 1;
    area3Right = areaSize * 3;
    if (area3Left <= pos && pos <= area3Right)
        return 0;
    long long nextPos = (pos + 4) / 5;
    return isOneRecursive(n - 1, nextPos);
}

int solution(int n, long long left, long long right)
{
    int ret = 0;

    while (left <= right)
    {
        if (isOneRecursive(n, left))
            ret++;
        left++;
    }
    return ret;
}
