#include <vector>
#include <queue>

struct st_pos
{
    int x;
    int y;
    int dir;
};

bool canMove(const std::vector<std::vector<int> >& maps, const st_pos& pos, int dir)
{
    if (pos.x < 0 || maps[0].size() <= pos.x || pos.y < 0 || maps.size() <= pos.y)
        return false;
    if (maps[pos.y][pos.x] != 1)
        return false;
    if (pos.dir == (dir + 2) % 4)
        return false;
    return true;
}

int solution(std::vector<std::vector<int> > maps)
{
    std::queue<st_pos> q;
    int dirX[4] = { 1, 0, -1, 0 };
    int dirY[4] = { 0, 1, 0, -1 };
    int x;
    int y;
    int dir;

    q.push({ 0, 0, 0 });
    while (!q.empty())
    {
        x = q.front().x;
        y = q.front().y;
        dir = q.front().dir;
        for (int i = 0; i < 4; i++)
        {
            if (canMove(maps, { x + dirX[i], y + dirY[i], i }, dir))
            {
                maps[y + dirY[i]][x + dirX[i]] = maps[y][x] + 1;
                q.push({ x + dirX[i], y + dirY[i], i });
            }
        }
        q.pop();
    }

    if (maps[maps.size() - 1][maps[0].size() - 1] == 1)
        return -1;
    return maps[maps.size() - 1][maps[0].size() - 1];
}
