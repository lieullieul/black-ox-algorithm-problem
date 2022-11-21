#include <string>
#include <vector>
#include <algorithm>

int solution(std::vector<int> cards)
{
    int cnt;
    int idx;
    int tmp;

    std::vector<int> loops;

    for (size_t i = 0; i < cards.size(); i++)
    {
        idx = i;
        if (cards[idx] == 0)
            continue;
        cnt = 0;
        while (cards[idx] != 0)
        {
            tmp = cards[idx];
            cards[idx] = 0;
            idx = tmp - 1;
            cnt++;
        }
        loops.push_back(cnt);
    }
    if (loops.size() < 2)
        return 0;
    std::sort(loops.begin(), loops.end());
    return loops[loops.size() - 1] * loops[loops.size() - 2];
}
