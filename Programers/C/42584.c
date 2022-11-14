#include <stdlib.h>

// 인덱스 스택
int g_stackIdx[100000];

// 배열 전체 탐색
// 현재 값이 탑보다 작으면 팝
//  -> 현재 위치와 탑과의 거리 저장
// 현재 값 푸시
// O(n) 탐색 + O(n-1) 팝
int* solution(int prices[], size_t prices_len)
{
    int* answer = (int*)malloc(sizeof(int) * prices_len);
    int top = 0;

    for (size_t i = 1; i + 1 < prices_len; i++)
    {
        while (top >= 0 && prices[g_stackIdx[top]] > prices[i])
        {
            answer[g_stackIdx[top]] = i - g_stackIdx[top];
            top--;
        }
        top++;
        g_stackIdx[top] = i;
    }
    while (top >= 0)
    {
        answer[g_stackIdx[top]] = (prices_len - 1) - g_stackIdx[top];
        top--;
    }
    answer[prices_len - 1] = 0;
    return answer;
}
