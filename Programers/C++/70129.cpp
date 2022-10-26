#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer(2, 0);
    string tmp;                 // 이진 변환 결과 저장할 임시 문자열
    int zeroCnt;                // 제거할 0의 갯수
    int size = s.size();

    // s의 길이가 1이 될 때까지 이진 변환
    while (size > 1)
    {
        tmp = "";
        zeroCnt = 0;

        // 0 제거
        for (size_t i = 0; i < size; i++)
        {
            if (s[i] == '0')
                zeroCnt++;
        }
        answer[1] += zeroCnt;

        // 0 제거 후 길이
        size -= zeroCnt;

        // 길이를 다시 문자열로
        // ex) 4 -> "0" -> "00" -> "100"
        // 반복 1회 당 대충 나머지 연산 + 나누기 연산 + 동적할당 + strjoin 필요
        // 비트 시프트 이용 시 총 17회 시프트, 18회 & 연산, 추가 char 변수 필요
        // 성능을 요구하는 문제는 아님
        while (size > 0)
        {
            tmp = static_cast<char>(size % 2 + '0') + tmp;
            size /= 2;
        }
        answer[0]++;

        // 다음 반복 위해 변수 초기화
        s = tmp;
        size = s.size();
    }
    return answer;
}
