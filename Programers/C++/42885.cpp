#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    size_t i = 0;
    size_t j = people.size() - 1;

    // 무게 내림차순으로 정렬
    sort(people.rbegin(), people.rend());

    // 인덱스 2개 사용
    // i = 남은 사람 중 제일 무거운 사람
    // j = 남은 사람 중 제일 가벼운 사람
    // 최고 뚱뚱이와 최고 날씬이가 같이 탈 수 있으면 날씬이 태움
    // 뚱뚱이는 아무튼 태움
    // i 리턴
    while (i <= j)
    {
        if (people[i] + people[j] <= limit)
            j--;
        i++;
    }
    return i;
}
