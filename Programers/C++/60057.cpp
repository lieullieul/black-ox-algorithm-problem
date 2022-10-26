#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    vector<string> vecCompStr;  // 압축된 문자열 벡터
    string strCnt;              // 숫자 -> 문자열
    string standard;            // 반복 확인할 기준 문자열
    string tmp;                 // vecCompStr에 저장할 임시 문자열
    size_t i;
    size_t cnt;                 // 기준 문자열이 몇 번 반복됐는지 체크할 변수
    size_t size = s.size();
    int answer = s.size();

    // stdDist = 기준 문자열의 길이
    // stdDist 1부터 s의 길이 반까지 늘려가며 탐색
    for (size_t stdDist = 1; stdDist <= size / 2; stdDist++)
    {
        tmp = "";
        i = 0;
        while (i < size)
        {
            // 기준 문자열이 반복되는 동안 횟수 체크
            cnt = 0;
            standard = s.substr(i, stdDist);
            while (!s.compare(i, stdDist, standard))
            {
                cnt++;
                i += stdDist;
                if (i >= size)
                    break;
            }

            // 2회 이상 반복 시 숫자 처리
            if (cnt > 1)
            {
                strCnt = "";
                while (cnt > 0)
                {
                    strCnt = static_cast<char>(cnt % 10 + '0') + strCnt;
                    cnt /= 10;
                }
                tmp += strCnt;
            }
            tmp += standard;
        }

        // stdDist 단위로 잘라냈을 때의 결과 저장
        vecCompStr.push_back(tmp);
    }

    // 가장 짧은 문자열 탐색
    for (int i = 0; i < vecCompStr.size(); i++)
    {
        if (vecCompStr[i].size() < answer)
            answer = vecCompStr[i].size();
    }
    return answer;
}
