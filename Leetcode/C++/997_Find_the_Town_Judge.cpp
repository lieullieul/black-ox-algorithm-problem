#include <vector>

using namespace std;

// 997. Find the Town Judge
// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int size = trust.size();

        vector<int> people(n, 0);
        vector<int> trusted(n, 0);
        for (int i = 0; i < size; i++)
        {
            people[trust[i][0] - 1]++;
            trusted[trust[i][1] - 1]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (people[i] == 0 && trusted[i] == n - 1)
                return i + 1;
        }
        return -1;
    }
};
