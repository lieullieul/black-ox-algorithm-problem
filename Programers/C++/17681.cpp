#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    string tmp;
    int mapInfo;

    // 비트연산
    // 두 지도 정보 OR 연산
    // 최상위 비트부터 AND 연산으로 벽 체크
    for (size_t i = 0; i < n; i++)
    {
        tmp = "";
        mapInfo = arr1[i] | arr2[i];
        for (size_t j = 1; j <= n; j++)
        {
            if (mapInfo & (0x01 << n - j))
                tmp += '#';
            else
                tmp += ' ';
        }
        answer.push_back(tmp);
    }
    return answer;
}
