#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    vector<int> combQueue;  // queue1 + queue2
    long long sumQ1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sumQ2 = accumulate(queue2.begin(), queue2.end(), 0);
    size_t q1front = 0;
    size_t q2front = queue1.size();
    size_t cqSize;
    int cnt = 0;

    // 두 벡터의 모든 원소들의 합이 홀수라면 얼리 리턴
    if ((sumQ1 + sumQ2) % 2)
        return -1;

    // combQueue 할당, 값 복사
    combQueue.reserve(queue1.size() + queue2.size());
    combQueue = queue1;
    combQueue.insert(combQueue.end(), queue2.begin(), queue2.end());

    // 푸시, 팝을 실제로 하면서 탐색할거라면 벡터 대신 큐
    // ex) q1.push(q2.front()); q1.pop();
    // 어차피 두 벡터에서 값이 순환함
    // 두 벡터를 합치고 그 안에서 각 벡터의 front만 이동시키면서 탐색
    cqSize = combQueue.size();
    while (q1front < cqSize && q2front < cqSize)
    {
        if (sumQ1 == sumQ2)
            return cnt;
        if (sumQ1 < sumQ2)
        {
            sumQ1 += combQueue[q2front];
            sumQ2 -= combQueue[q2front];
            q2front++;
        }
        else
        {
            sumQ1 -= combQueue[q1front];
            sumQ2 += combQueue[q1front];
            q1front++;
        }
        cnt++;
    }
    return -1;
}
