#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// 154538 숫자 변환하기
// https://school.programmers.co.kr/learn/courses/30/lessons/154538

int solution(int x, int y, int n) {
    int answer = 0;
    queue<pair<int, int>> q;
    set<int> s;

    q.push({x, 0});
    while (!q.empty())
    {
        int val = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (val == y)
            return cnt;

        cnt++;
        if (s.find(val + n) == s.end() && val + n <= y)
        {
            s.insert(val + n);
            q.push({val + n, cnt});
        }
        if (s.find(val * 2) == s.end() && val * 2 <= y)
        {
            s.insert(val * 2);
            q.push({val * 2, cnt});
        }
        if (s.find(val * 3) == s.end() && val * 3 <= y)
        {
            s.insert(val * 3);
            q.push({val * 3, cnt});
        }
    }
    return -1;
}
