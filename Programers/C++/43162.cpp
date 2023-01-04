#include <vector>
#include <queue>

int solution(int n, std::vector<std::vector<int>> computers)
{
    std::queue<int> q;
    int idx;
    int cnt;

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (computers[i][i] != 0)
        {
            q.push(i);
            while (!q.empty())
            {
                idx = q.front();
                computers[idx][idx] = 0;
                for (int j = 0; j < n; j++)
                {
                    if (computers[idx][j])
                    {
                        computers[idx][j] = 0;
                        computers[j][idx] = 0;
                        q.push(j);
                    }
                }
                q.pop();
            }
            cnt++;
        }
    }
    return cnt;
}
