#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 42746 가장 큰 수
// https://school.programmers.co.kr/learn/courses/30/lessons/42746

// 붙여서 큰 수가 되는 쪽
bool compare(string& a, string& b)
{
    string ab = a + b;
    string ba = b + a;

    return atoi(ab.c_str()) > atoi(ba.c_str());
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    vector<string> v(size);

    for (int i = 0; i < size; i++)
    {
        v[i] = to_string(numbers[i]);
    }

    // 정렬
    sort(v.begin(), v.end(), compare);

    // 예외 처리 - 모든 원소가 0
    if (v[0] == "0")
        return string("0");

    for (int idx = 0; idx < size; idx++)
    {
        answer += v[idx];
    }

    return answer;
}
