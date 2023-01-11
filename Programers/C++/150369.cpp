#include <vector>

long long solution(int cap, int n, std::vector<int> deliveries, std::vector<int> pickups)
{
    long long dist;
    int dIdx;
    int pIdx;
    int maxIdx;
    int tmp;

    dist = 0;
    maxIdx = n - 1;
    while (maxIdx >= 0)
    {
        dIdx = maxIdx;
        pIdx = maxIdx;
        while (dIdx >= 0 && !deliveries[dIdx])
            dIdx--;
        while (pIdx >= 0 && !pickups[pIdx])
            pIdx--;
        if (dIdx > pIdx)
            dist += dIdx * 2 + 2;
        else
            dist += pIdx * 2 + 2;

        tmp = 0;
        while (dIdx >= 0 && tmp < cap)
        {
            if (cap - tmp >= deliveries[dIdx])
            {
                tmp += deliveries[dIdx];
                deliveries[dIdx] = 0;
                dIdx--;
            }
            else
            {
                deliveries[dIdx]--;
                tmp++;
            }
        }
        tmp = 0;
        while (pIdx >= 0 && tmp < cap)
        {
            if (cap - tmp >= pickups[pIdx])
            {
                tmp += pickups[pIdx];
                pickups[pIdx] = 0;
                pIdx--;
            }
            else
            {
                pickups[pIdx]--;
                tmp++;
            }
        }

        if (dIdx > pIdx)
            maxIdx = dIdx;
        else
            maxIdx = pIdx;
    }
    return dist;
}