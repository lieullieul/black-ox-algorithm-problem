#include <vector>

// 전역변수
std::vector<int> g_result;
int g_diffMax;

// 현재 저장된 경우의 수 보다 작은 점수를 더 많이 쐈는지 비교
bool hasSmallScore(std::vector<int>& ryan)
{
    // 0점부터 10점 순으로 탐색
    // 같지 않은 경우 바로 리턴
    for (size_t i = 0; i < 11; i++)
    {
        if (ryan[10 - i] > g_result[10 - i])
            return true;
        if (ryan[10 - i] < g_result[10 - i])
            return false;
    }
    return false;
}

// dfs
// 라이언의 점수판 완성 시 점수 비교
// 더 큰 점수차로 이긴 점수판 저장
// 점수차가 같다면 비교
void dfs(int shotCnt, int n, std::vector<int> &apeach, std::vector<int> &ryan, size_t score)
{
    // 10~0점 까지 모두 탐색한 경우
    if (score == 11)
    {
        // n발 모두 쏜 경우
        if (shotCnt == n)
        {
            int ryanScore = 0;
            int apeachScore = 0;

            // 점수 계산
            for (size_t i = 0; i < 11; i++)
            {
                if (ryan[i] > apeach[i])
                    ryanScore += (10 - i);
                else if (ryan[i] < apeach[i])
                    apeachScore += (10 - i);
                else if (ryan[i] == apeach[i])
                {
                    if (apeach[i])
                        apeachScore += (10 - i);
                }
            }
            if (ryanScore - apeachScore < g_diffMax)
                return ;
            if (ryanScore - apeachScore == g_diffMax && g_diffMax != 0 && !hasSmallScore(ryan))
                return ;
            g_diffMax = ryanScore - apeachScore;
            g_result = ryan;
        }
        return ;
    }

    int shot = 0;

    // 같은 점수에 어피치 보다 한발 더 쏜 경우까지만 탐색
    while (shot <= apeach[score] + 1)
    {
        ryan[score] = shot;
        shotCnt += shot;
        dfs(shotCnt, n, apeach, ryan, score + 1);
        ryan[score] = 0;
        shotCnt -= shot;
        shot++;
    }
}

std::vector<int> solution(int n, std::vector<int> apeach)
{
    std::vector<int> ryan(apeach.size(), 0);

    dfs(0, n, apeach, ryan, 0);

    // diffMax가 0 -> 라이언이 이길 수 있는 경우의 수 없음
    if (g_diffMax == 0)
        return std::vector<int>(1, -1);
    return g_result;
}
