#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid)
{
    vector<int> answer;
    vector<vector<vector<int>>> check;  // 사이클 체크 3차원 벡터
    vector<int> dirX = {1, 0, -1, 0};   // 우, 하, 좌, 상 방향
    vector<int> dirY = {0, -1, 0, 1};
    int x;                              // 3차원 벡터 x 좌표
    int y;                              // 3차원 벡터 y 좌표
    int dir;                            // 3차원 벡터 z 좌표
    int cycleLen;                       // 사이클 길이

    // 3차원 벡터 할당 및 초기화
    check.reserve(grid.size());
    for (int i = 0; i < grid.size(); i++)
    {
        check[i].reserve(grid[i].size());
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            check[i][j].resize(4);
        }
    }

    // 그리드의 각 칸에서 4방향으로 빛을 쏠 때에 대해 전체 탐색
    // [row][col][k]에 방문했다면 사이클 성립 (시작지점 재방문)
    // -> 이전 좌표에서 [row][col] 좌표로 k방향으로 전진해서 들어옴
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[row].size(); col++)
        {
            // k = 방향
            // 0 ~ 3 -> 우 하 좌 상
            for (int k = 0; k < 4; k++)
            {
                x = col;
                y = row;
                dir = k;
                cycleLen = 0;

                // 방문 체크, 전진 반복하며 탐색
                while (!check[y][x][dir])
                {
                    // 좌표, 방향 체크하고 사이클 + 1
                    check[y][x][dir] = cycleLen++;

                    // 지시에 따라 방향 전환
                    if (grid[y][x] == 'L')
                        dir = (dir - 1 + 4) % 4;
                    else if (grid[y][x] == 'R')
                        dir = (dir + 1 + 4) % 4;

                    // 전진
                    x = (x + dirX[dir] + grid[y].size()) % grid[y].size();
                    y = (y + dirY[dir] + grid.size()) % grid.size();

                    // 시작 좌표에 같은 방향으로 들어온 경우 사이클 성립하므로
                    // 리턴할 벡터에 값 넣고 반복문 탈출
                    if (x == col && y == row && dir == k)
                    {
                        answer.push_back(cycleLen);
                        break;
                    }
                }
            }
        }
    }

    // 결과 오름차순 정렬
    sort(answer.begin(), answer.end());
    return answer;
}
