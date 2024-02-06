#include <string>
#include <vector>

using namespace std;

// 68645 삼각 달팽이
// https://school.programmers.co.kr/learn/courses/30/lessons/68645


// 수학?적으로 해결함
// 3분할
// 공통 - 각 변 당 (n - 1) - (완료 루프 * 3) 번 씩 수행
// 좌변 - idx 이동 보정값 필요 dist1 -> 초기 1, 루프 당 +2
// 하변 - idx++
// 우변 - idx 이동 보정값 필요 dist3 - > 초기 n, 루프 당 -1
//      - 마지막 수행은 (루프 + 1) * 2 만큼 idx 이동

vector<int> solution(int n) {
    vector<int> answer;

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    answer.resize(sum, 0);

    int num = 1;
    int idx = 0;
    int dist1 = 1;
    int cnt = 0;
    int cntMax = n - 1;
    int dist3 = n;
    int dist3Max = n;
    int way = 1;
    int loop = 0;

    while (num <= sum)
    {
        switch (way)
        {
        case 1:
            if (cnt < cntMax)
            {
                answer[idx] = num++;
                idx += dist1 + cnt;
                cnt++;
            }
            else
            {
                cnt = 0;
                way = 2;
                dist1 += 2;
            }
            break;

        case 2:
            if (cnt < cntMax)
            {
                answer[idx++] = num++;
                cnt++;
            }
            else
            {
                cnt = 0;
                way = 3;
            }
            break;

        case 3:
            answer[idx] = num++;
            if (cnt < cntMax - 1)
            {
                idx -= dist3;
                dist3--;
                cnt++;
            }
            else
            {
                idx += 2 * ++loop;
                cnt = 0;
                cntMax -=3;
                dist3Max--;
                dist3 = dist3Max;
                way = 1;
            }
            break;
        }
    }

    return answer;
}
