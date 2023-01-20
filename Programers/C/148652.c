// int isOneRecursive(int n, long long pos)
// {
//     if (n == 1)
//         return pos != 3;
//     if ((pos + 4) % 5 == 2)
//         return 0;
//     long long nextPos = (pos + 4) / 5;
//     return isOneRecursive(n - 1, nextPos);
// }

// int solution(int n, long long left, long long right)
// {
//     int ret = 0;

//     while (left <= right)
//     {
//         if (isOneRecursive(n, left))
//             ret++;
//         left++;
//     }
//     return ret;
// }

int solution(int n, long long left, long long right)
{
    int ret;
    int depth;
    long long pos;

    ret = 0;
    while (left <= right)
    {
        depth = n;
        pos = left;
        while (depth > 1)
        {
            if ((pos + 4) % 5 == 2)
            {
                pos = 3;
                break;
            }
            pos = (pos + 4) / 5;
            depth--;
        }
        ret += (pos != 3);
        left++;
    }
    return ret;
}
