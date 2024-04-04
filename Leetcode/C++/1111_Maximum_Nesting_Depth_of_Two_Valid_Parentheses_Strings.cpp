#include <string>
#include <vector>

using namespace std;

// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings

// description is trash

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int size = seq.size();
        int st = 0;
        vector<int> ret;

        for (int i = 0; i < size; i++)
        {
            if (seq[i] == '(')
                st++;
            ret.push_back(st % 2);
            if (seq[i] == ')')
                st--;
        }
        return ret;
    }
};
