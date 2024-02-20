#include <queue>
#include <vector>

using namespace std;

// 1642
// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        int size = heights.size();
        int idx = 0;

        // diff <= 0 이면 그냥 이동가능
        // diff를 우선순위 큐에 push
        // 큐에서 가장 작은 원소만큼 bricks에서 빼기
        // 0보다 작으면 이동 불가능
        while (idx + 1 < size)
        {
            int diff = heights[idx + 1] - heights[idx];
            if (diff > 0)
                pq.push(diff);

            if (pq.size() > ladders)
            {
                bricks -= pq.top();
                pq.pop();
            }

            if (bricks < 0)
                break;

            idx++;
        }

        return idx;
    }
};
