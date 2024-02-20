#include <string>
#include <vector>

using namespace std;

// 42883 큰 수 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/42883

// 뒷 수가 더 크면 현재 인덱스 삭제
// k개 지울 때 까지 반복
string solution(string number, int k) {
    int size = number.size();

    while (k > 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (i + 1 == size)
            {
                number.erase(i, 1);
                break;
            }

            if (number[i] < number[i + 1])
            {
                number.erase(i, 1);
                break;
            }
        }
        size--;
        k--;
    }

    return number;
}

int main()
{
    // solution("1924", 2);
    solution("1231234", 3);
}
