#include <stdlib.h>

// 0번 비트부터 1이 연속적으로 나타난 횟수 리턴
size_t getContinualBit(long long val)
{
    size_t cnt;
    size_t i;

    cnt = 0;
    i = 0;
    while ((val >> i) & 0x01)
    {
        cnt++;
        i++;
    }
    return cnt;
}

// val보다 큰 수 중에 비트가 1 혹은 2 차이나는 가장 작은 수
long long getTargetNum(long long val)
{
    size_t exponent;
    long long tmp;

    // 1이 연속되서 나타난 횟수
    exponent = getContinualBit(val);

    // (횟수 - 1) 비트에 넣기위해 -1
    if (exponent > 0)
        exponent--;

    // m1 pro, Ventura 13.0.1, clang
    // 한 번에 31 이상 시프트가 안되서 부득이 나눠서 시프트
    tmp = 0x01;
    while (exponent > 30)
    {
        tmp = tmp << 30;
        exponent -= 30;
    }
    tmp = tmp << exponent;
    return val + tmp;
}

// 7 -> 11 , 0111 -> 1011
// 15 -> 23, 0000 1111 -> 0001 0111
// 31 -> 47, 0001 1111 -> 0010 1111
// 0번 비트가 0이라면 +1 한 수가 가장 작은 수
// 0번 비트가 1이라면
//   -> 최하위 비트부터 연속적으로 나타난 위치에 1 더하면 비트 2개가 변하는 가장 작은 수
long long* solution(long long numbers[], size_t numbers_len)
{
    long long* answer;

    answer = (long long*)malloc(sizeof(long long) * numbers_len);
    if (!answer)
        return NULL;
    for (size_t i = 0; i < numbers_len; i++)
    {
        answer[i] = getTargetNum(numbers[i]);
    }
    return answer;
}
