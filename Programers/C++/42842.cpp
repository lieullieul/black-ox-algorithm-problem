#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 0);
    int area = brown + yellow;      // 사각형의 넓이
    int xySum = (brown + 4) / 2;    // 가로변의 길이 + 세로변의 길이
    int x;
    int y;

    // 연립방정식
    // x * y = area
    // x + y = xySum
    for (y = 1; y < xySum; y++)
    {
        x = xySum - y;
        if (x * y == area)
            break;
    }
    answer[0] = x;
    answer[1] = y;
    return answer;
}
