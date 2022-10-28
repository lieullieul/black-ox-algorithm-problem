#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times)
{
    size_t guardSize = scope.size();
    size_t guardIdx;
    int now;                            // 탐색 중 현재 위치
    int cycle;                          // 경비병 근무 휴식 주기
    int answer = distance;              // 무사히 지나간다면 distance 리턴

    // 각 경비병의 감시 구간 정렬
    for (size_t i = 0; i < guardSize; i++)
    {
        sort(scope[i].begin(), scope[i].end());
    }

    // 경비병들의 감시 구역을 지날 때
    // 각 경비병들의 근무 여부 체크
    // 근무 중이라면 발각 위치 저장
    // 그 중 제일 빨리 발각된 위치 리턴
    guardIdx = 0;
    while (guardIdx < guardSize)
    {
        now = scope[guardIdx][0];
        cycle = times[guardIdx][0] + times[guardIdx][1];
        while (now <= scope[guardIdx][1])
        {
            if (now > answer)
                break;
            if ((now - 1) % cycle < times[guardIdx][0])
                answer = now;
            now++;
        }
        guardIdx++;
    }
    return answer;
}
