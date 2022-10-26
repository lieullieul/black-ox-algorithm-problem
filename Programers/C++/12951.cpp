#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";

    // 첫 문자가 알파벳이라면 대문자로
    answer += toupper(s[0]);

    // 앞 문자가 공백
    // 현재 문자가 알파벳이라면 대문자로
    // 아니라면 소문자로
    for (size_t i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == ' ')
            answer += toupper(s[i]);
        else
            answer += tolower(s[i]);
    }
    return answer;
}
