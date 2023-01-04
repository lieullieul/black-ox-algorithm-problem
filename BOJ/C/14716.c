#include <stdio.h>

typedef struct s_pos
{
    int x;
    int y;
}t_pos;

int g_m;
int g_n;
int g_map[250][250];
t_pos g_pos[8] = {
    { -1, -1 }, { 0, -1 }, { 1, -1 },
    { -1, 0 },             { 1, 0 },
    { -1, 1 },  { 0, 1 },  { 1, 1 }
};

void dfs(int x, int y)
{
    // escape condition
    if (x < 0 || g_n <= x || y < 0 || g_m <= y)
        return ;
    if (g_map[y][x] == 0)
        return ;

    // logic
    g_map[y][x] = 0;
    for (int i = 0; i < 8; i++)
    {
        dfs(x + g_pos[i].x, y + g_pos[i].y);
    }
}

int main()
{
    int result;

    scanf("%d %d", &g_m, &g_n);

    for (int i = 0; i < g_m; i++)
    {
        for (int j = 0; j < g_n; j++)
        {
            scanf(" %d", &g_map[i][j]);
        }
    }

    result = 0;
    for (int i = 0; i < g_m; i++)
    {
        for (int j = 0; j < g_n; j++)
        {
            if (g_map[i][j] == 1)
            {
                dfs(j, i);
                result++;
            }
        }
    }
    printf("%d", result);

    return 0;
}
