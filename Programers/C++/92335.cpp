#include <string>
#include <algorithm>

using namespace std;

// 소수 판별 함수
bool isPrime(long long num)
{
    if (num < 2)
        return false;
    for (size_t i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k)
{
    string baseStr = "";
    string tmp;
    size_t baseStrSize;
    size_t begin;
    size_t end;
    int cnt;

    // ex) 2147483647 -> "7463847412" -> "2147483647"
    while (n > 0)
    {
        baseStr += (char)(n % k + '0');
        n /= k;
    }
    reverse(baseStr.begin(), baseStr.end());

    // 변환한 문자열에서 0 위치 찾기
    // 0 앞까지 잘라서 숫자로 변환하고 소수인지 판별
    // 다시 시작 위치 찾기
    baseStrSize = baseStr.size();
    begin = 0;
    cnt = 0;
    while (begin != string::npos)
    {
        end = baseStr.find('0', begin);
        if (end == string::npos)
            end = baseStrSize;
        tmp = baseStr.substr(begin, end - begin);
        if (isPrime(stoll(tmp)))
            cnt++;
        begin = baseStr.find_first_not_of('0', end);
    }
    return cnt;
}
