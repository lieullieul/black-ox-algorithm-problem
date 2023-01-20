#include <math.h>

int isOneRecursive(int n, long long pos)
{
    if (n == 1)
        return pos != 3;
    if ((pos + 4) % 5 == 2)
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
