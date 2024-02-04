#include <string>
#include <vector>

using namespace std;

// 뒤에 있는 큰 수 찾기

// 정수로 이루어진 배열 numbers가 있습니다.
// 배열의 각 원소들에 대해 자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 뒷 큰수라고 합니다.
// 정수 배열 numbers가 매개변수로 주어질 때, 모든 원소에 대한 뒷 큰수들을 차례로 담은 배열을 return 하도록 solution 함수를 완성해주세요.
// 단, 뒷 큰수가 존재하지 않는 원소는 -1을 담습니다.

vector<int> solution(vector<int> numbers) {
    int size = numbers.size();
    vector<int> answer(size, -1);

    // 마지막 원소는 항상 -1
    // 뒤에서부터
    for (int i = size - 2; i >= 0; i--)
    {
        // 타겟 원소의 뒷 큰수 찾기
        for (int j = i + 1; j < size; j++)
        {
            // 뒷 큰수 찾은 경우
            if (numbers[i] < numbers[j])
            {
                answer[i] = numbers[j];
                break;
            }
            else
            {
                // 뒷 큰수가 아닌 경우 - 현재 값이 이전 값보다 크거나 같음
                // - 직전에 뒷 큰 수가 없었다면 이번에도 없음
                // - 직전의 결과보다 현재 값이 작다면 직전 결과와 이번 결과가 같음
                if (answer[j] == -1 || numbers[i] < answer[j])
                {
                    answer[i] = answer[j];
                    break;
                }
            }
        }
    }
    return answer;
}

int main()
{
    solution({2,3,3,5});
}
