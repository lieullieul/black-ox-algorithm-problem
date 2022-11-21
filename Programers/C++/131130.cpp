#include <string>
#include <vector>

int solution(std::vector<int> cards)
{
    int answer = 0;

    for (size_t i = 0; i < cards.size(); i++)
    {
        if (cards[i] == i + 1)
            cards[i] = 0;
    }
    return answer;
}