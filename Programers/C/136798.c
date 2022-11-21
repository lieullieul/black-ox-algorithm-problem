int g_cnt[100001];

int solution(int number, int limit, int power)
{
    int cnt;
    int answer = 0;

    g_cnt[1] = 1;
    for (int i = 2; i <= number; i++)
    {
        cnt = 1;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
                cnt++;
        }
        g_cnt[i] = cnt;

    }

    for (int i = 1; i <= number; i++)
    {
        if (g_cnt[i] > limit)
            answer += power;
        else
            answer += g_cnt[i];
    }
    return answer;
}
