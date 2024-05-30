#include <string>

using namespace std;

// 1404. Number of Steps to Reduce a Number in Binary Representation to One
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one

// 홀수면 +1, 짝수면 /2
// 최대 500자리 문자열
// 올림이 발생한 경우 추가 처리
// - 올린 후 홀수라면 어차피 다시 올림 발생
// - 올린 후 짝수라면 그 과정에서 올림 발생

class Solution {
public:
    int numSteps(string s) {
        int size = s.size();
        int act = 0;
        int carry = 0;

        for (int i = size - 1; i > 0; i--)
        {
            if (s[i] - '0' + carry == 1)
            {
                carry = 1;
                act += 2;
            }
            else
                act++;
        }
        return act + carry;
    }
};
