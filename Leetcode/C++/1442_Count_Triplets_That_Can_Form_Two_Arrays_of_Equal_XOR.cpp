#include <string>
#include <vector>

using namespace std;

// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor

// xor 결과가 0이 되는 모든 하위 배열 찾기
// 해당 배열을 어떻게 나눠도 양쪽 배열의 xor 값은 같음

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        int ret = 0;

        // 모든 하위 배열 탐색 O(N^2)
        for (int i = 0; i + 1 < size; i++)
        {
            int target = arr[i];
            for (int j = i + 1; j < size; j++)
            {
                target ^= arr[j];

                // xor 결과가 0이라면 배열 길이 -1만큼 더하기
                if (target == 0)
                    ret += j - i;
            }
        }
        return ret;
    }
};
