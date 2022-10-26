#include <string>
#include <vector>

// 소수점 4자리까지 계산 보장
// 10000까지의 자연수로 만들 수 있는 가장 작은 유리수 1/10000 == 0.0001
#define PRECISION 10000

using namespace std;

int solution(int n)
{
    int answer = 1;
    float tmp;

    // n / i == 가운데 수
    // n / i + (1 - i) / 2 == 첫 번째 수
    // float 일정 구간 이후 신뢰성 떨어짐
    // int 정밀도 직접 조절 가능하나 표현가능 범위 한계
    // int tmp = n * PRECISION / i + (PRECISION - i * PRECISION) / 2;
    for (int i = 2; i <= n; i++)
    {
        tmp = (float)n / i + (float)(1 - i) / 2;

        // 첫 번째 수가 정수가 아니라면 패스
        if ((int)(tmp * PRECISION) % PRECISION)
            continue;

        // 첫 번째 수가 1보다 작으면 바로 탐색 종료
        if (tmp < 1.0f)
            break;
        answer++;
    }
    return answer;
}
