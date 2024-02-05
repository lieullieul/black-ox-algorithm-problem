#include <string>
#include <vector>
#include <stack>

using namespace std;

// 131704 택배상자
// https://school.programmers.co.kr/learn/courses/30/lessons/131704

int solution(vector<int> order) {
    int size = order.size();
    int answer = 0;
    int idx = 0;
    stack<int> st;

    // 일단 스택에 넣고
    // order[answer]와 스택의 탑이 같은지 확인
    for (int i = 1; i <= size; i++)
    {
        st.push(i);

        while (!st.empty() && order[answer] == st.top())
        {
            st.pop();
            answer++;
        }
    }

    return answer;
}
