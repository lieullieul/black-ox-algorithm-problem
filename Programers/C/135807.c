#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 오름차순
int compare(const void* a, const void* b)
{
    return *(int *)a - *(int *)b;
}

// 안나눠지면 true
bool canNotDivide(int arr[], size_t len, int val)
{
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] % val == 0)
            return false;
    }
    return true;
}

// 나눠지면 true
bool canDivide(int arr[], size_t len, int val)
{
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] % val)
            return false;
    }
    return true;
}

int solution(int arrayA[], size_t arrayA_len, int arrayB[], size_t arrayB_len)
{
    int chulsoo = 0;
    int younghee = 0;

    // 채점 시 이미 정렬된 케이스만 입력으로 들어오는 것으로 보이지만
    // 문제에 명시적으로 쓰여있지 않기 때문에 정렬함
    qsort(arrayA, arrayA_len, sizeof(int), compare);
    qsort(arrayB, arrayB_len, sizeof(int), compare);

    // 철수 카드
    // 가장 작은 원소 값을 제수로하여 내림차순 탐색
    // 제수가 모든 원소의 약수면 탐색 종료
    //  -> 결국 제수의 약수 이외에 더 성립하는 경우의 수가 없음
    for (int i = arrayA[0]; i >= 2; i--)
    {
        if (canDivide(arrayA, arrayA_len, i))
        {
            chulsoo = i;
            break;
        }
    }
    // 영희 카드
    // 위의 조건을 만족하는 수가 존재할 때
    // 그 수가 영희 카드의 약수라면
    // chulsoo 0으로
    if (chulsoo != 0)
    {
        if (!canNotDivide(arrayB, arrayB_len, chulsoo))
            chulsoo = 0;
    }

    // 바꿔서 반복
    for (int i = arrayB[0]; i >= 2; i--)
    {
        if (canDivide(arrayB, arrayB_len, i))
        {
            younghee = i;
            break;
        }
    }
    if (younghee != 0)
    {
        if (!canNotDivide(arrayA, arrayA_len, younghee))
            younghee = 0;
    }

    // 두 결과값 중 큰 값 리턴
    return chulsoo > younghee ? chulsoo : younghee;
}
