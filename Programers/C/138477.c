#include <stdlib.h>

int* solution(int k, int score[], size_t score_len)
{
    int* hof;   // 명예의 전당
    int* answer;
    int min;
    int idx;

    hof = (int *)malloc(sizeof(int) * k);
    if (!hof)
        return NULL;
    answer = (int *)malloc(sizeof(int) * score_len);
    if (!answer)
        return NULL;
    min = 2001;
    for (size_t i = 0; i < score_len; i++)
    {
        // hof 배열이 다 차기 전에는 최소값과 위치만 저장
        if (i < k)
        {
            hof[i] = score[i];
            if (score[i] < min)
            {
                idx = i;
                min = score[i];
            }
        }
        else
        {
            // 현재 값이 hof의 최소값보다 크다면 교체
            // 다시 최소값과 위치 탐색
            if (score[i] > min)
            {
                hof[idx] = score[i];
                min = 2001;
                for (size_t j = 0; j < k; j++)
                {
                    if (hof[j] < min)
                    {
                        idx = j;
                        min = hof[j];
                    }
                }
            }
        }
        answer[i] = min;
    }
    free(hof);
    return answer;
}
