#include <string>
#include <vector>

using namespace std;

// 68936 쿼드압축 후 개수 세기
// https://school.programmers.co.kr/learn/courses/30/lessons/68936

// 4등분
// 영역이 모두 같은 수라면 탐색 종료
vector<int> g_answer(2, 0);
void recursive(int dist, int startX, int startY, vector<vector<int>>& arr)
{
    int filled = dist * dist;
    int sum = 0;
    for (int y = startY; y < startY + dist; y++)
    {
        for (int x = startX; x < startX + dist; x++)
        {
            sum += arr[y][x];
        }
    }

    if (sum == filled)
    {
        g_answer[1]++;
        return;
    }
    else if (sum == 0)
    {
        g_answer[0]++;
        return;
    }
    else
    {
        int nextDist = dist / 2;
        recursive(nextDist, startX, startY, arr);
        recursive(nextDist, startX + nextDist, startY, arr);
        recursive(nextDist, startX, startY + nextDist, arr);
        recursive(nextDist, startX + nextDist, startY + nextDist, arr);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    int dist = arr.size();

    recursive(dist, 0, 0, arr);

    return g_answer;
}

