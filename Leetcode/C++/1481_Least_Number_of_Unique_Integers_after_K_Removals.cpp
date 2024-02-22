#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// 1481. Least Number of Unique Integers after K Removals
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        int size = arr.size();

        for (int i = 0; i < size; i++)
        {
            um[arr[i]]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& iter : um)
        {
            pq.push(iter.second);
        }

        for (;;)
        {
            k -= pq.top();
            if (k < 0)
                break;
            pq.pop();
        }

        return pq.size();
    }
};

int main()
{
    Solution a;

    vector<int> v = {5, 5, 4};

    a.findLeastNumOfUniqueInts(v, 1);
}
