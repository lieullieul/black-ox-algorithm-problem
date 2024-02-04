#include <string>
#include <vector>
#include <map>

using namespace std;

// 132265 롤케이크 자르기
// https://school.programmers.co.kr/learn/courses/30/lessons/132265

int solution(vector<int> topping) {
    int answer = 0;
    int size = topping.size();
    map<int, int> m1;
    map<int, int> m2;


    for (int i = 0; i < size; i++)
        m2[topping[i]]++;

    for (int i = 0; i < size; i++)
    {
        m1[topping[i]]++;
        m2[topping[i]]--;
        if (m2[topping[i]] == 0)
            m2.erase(topping[i]);

        if (m1.size() == m2.size())
            answer++;
    }

    return answer;
}
