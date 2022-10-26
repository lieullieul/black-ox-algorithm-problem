#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer(2, 0);
    map<string, bool> cmp;      // 중복 체크 맵

    // 첫 단어 프리 패스
    cmp[words[0]] = true;

    // 두 번째 단어부터
    // 이미 맵에 있거나, 끝말잇기가 성립되지 않는 경우
    // 낱말 순서 % 사람 수 + 1 = 틀린 사람
    // 낱말 순서 / 사람 수 + 1 = 그 사람이 틀린 순서
    for (int i = 1; i < words.size(); i++)
    {
        if (cmp[words[i]] || words[i - 1].back() != words[i].front())
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            return answer;
        }
        else
            cmp[words[i]] = true;
    }
    return answer;
}
