#include <vector>
#include <algorithm>

using namespace std;

// 268. Missing Number
// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        int total = (n * (n + 1)) / 2;

        return total - sum;
    }
};
