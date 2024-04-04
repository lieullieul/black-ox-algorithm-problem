#include <string>

using namespace std;

// 1614. Maximum Nesting Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int max = 0;
        int size = s.size();

        int st = 0;

        for (int i = 0; i < size; i++)
        {
            if (s[i] == '(')
                st++;
            if (s[i] == ')')
            {
                if (st == 0)
                    return 0;
                st--;
            }

            if (st > max)
                max = st;
        }

        if (st > 0)
            return 0;
        return max;
    }
};
