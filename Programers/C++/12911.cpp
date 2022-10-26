// n은 100만 이하 자연수
// 11110100001001000000 비트 20개로 표현 가능
#define MAX_COUNT 20

int solution(int n)
{
    int bitCnt = 0;
    int targetBitCnt;

    //n의 1인 비트 체크
    for (int i = 0; i < MAX_COUNT; i++)
    {
        if (n & (0x01 << i))
            bitCnt++;
    }

    // n + 1부터 1씩 올리며 1인 비트 체크
    // n과 같다면 리턴
    for (int i = n + 1; n <= 1000000; i++)
    {
        targetBitCnt = 0;
        for (int j = 0; j < MAX_COUNT; j++)
        {
            if (i & (0x01 << j))
                targetBitCnt++;
        }
        if (targetBitCnt == bitCnt)
            return i;
    }
    return 0;
}
