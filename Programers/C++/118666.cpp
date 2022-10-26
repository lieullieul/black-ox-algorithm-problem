#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    map<char, int> score;   //각 유형 점수 저장할 맵
    string answer = "";

    // 1~3번 선택 시 첫 번째 유형 점수 더하기
    // 5~7번 선택 시 두 번쩨 유형 점수 더하기
    for (int i = 0; i < survey.size(); i++)
    {
        if (choices[i] == 4)
            continue;
        if (choices[i] < 4)
            score[survey[i][0]] += abs(choices[i] - 4);
        else
            score[survey[i][1]] += abs(choices[i] - 4);
    }

    // 대응하는 유형 중 더 높은 유형 문자열에 저장
    // 같은 경우 사전 순으로
    if (score['R'] >= score['T'])
        answer += 'R';
    else
        answer += 'T';

    if (score['C'] >= score['F'])
        answer += 'C';
    else
        answer += 'F';

    if (score['J'] >= score['M'])
        answer += 'J';
    else
        answer += 'M';

    if (score['A'] >= score['N'])
        answer += 'A';
    else
        answer += 'N';

    return answer;
}
