int solution(int number, int limit, int power)
{
    int cnt;
    int answer = 1;

    for (int i = 2; i <= number; i++)
    {
        cnt = 1;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
                cnt++;
        }
        if (cnt > limit)
            answer += power;
        else
            answer += cnt;
    }
    return answer;
}
