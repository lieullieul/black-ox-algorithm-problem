#include <vector>
#include <unordered_map>

using namespace std;

// 1. Two Sum
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;

        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            int val = target - nums[i];
            auto iter = hm.find(val);
            if (iter != hm.end())
            {
                return { hm[val], i };
            }
            hm[nums[i]] = i;
        }
        return vector<int>();
    }
};
