#include <string>
#include <vector>

using namespace std;

// 49994 방문 길이
// https://school.programmers.co.kr/learn/courses/30/lessons/49994

// 가로, 세로 방문 체크용 2차원 배열
int g_horizontal[11][11];
int g_vertical[11][11];

int solution(string dirs) {
    int size = dirs.size();
    int posX = 5;
    int posY = 5;

    // 명령어 순회
    for (int i = 0; i < size; i++)
    {
        // 지나간 길 체크
        switch (dirs[i])
        {
        case 'L':
            if (posX > 0)
            {
                posX--;
                g_horizontal[posY][posX] = 1;
            }
            break;

        case 'R':
            if (posX < 10)
            {
                g_horizontal[posY][posX] = 1;
                posX++;
            }
            break;
        case 'U':
            if (posY > 0)
            {
                posY--;
                g_vertical[posY][posX] = 1;
            }
            break;

        case 'D':
            if (posY < 10)
            {
                g_vertical[posY][posX] = 1;
                posY++;
            }
            break;
        }
    }

    // 취합
    int answer = 0;
    for (int y = 0; y < 11; y++)
    {
        for (int x = 0; x < 11; x++)
        {
            answer += g_horizontal[y][x] + g_vertical[y][x];
        }
    }

    return answer;
}
