#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> st;
    size_t len = s.size();

    // 길이가 홀수면 불가능
    if (len % 2)
        return 0;

    // 문자열 탐색
    // 스택이 비어 있으면 푸시
    // 스택의 탑과 현재 문자가 같으면 팝
    // 다르면 푸시
    // 괄호문자열 문제와 비슷
    for (size_t i = 0; i < len; i++)
    {
        if (st.empty())
            st.push(s[i]);
        else if (st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }

    // 스택이 비어 있으면 모두 짝지어 제거했으므로 가능
    // 아니라면 불가능
    return st.empty();
}
