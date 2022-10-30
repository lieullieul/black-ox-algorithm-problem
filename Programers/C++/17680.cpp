#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    unordered_map<string, list<string>::iterator> cacheIter; // 캐시에 있는 각 값들의 주소 저장
    list<string> cache;
    size_t citiesSize = cities.size();
    int time = 0;

    // 캐시사이즈가 0이면 캐시 미스
    if (cacheSize == 0)
        return citiesSize * 5;

    // 리스트에 값 넣고
    // 그 주소를 비정렬 맵에 저장 -> 굳이 정렬할 이유가 없음
    for (size_t i = 0; i < citiesSize; i++)
    {
        // 대소문자 구분 없기 때문에 전부 소문자로 변환
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        // 캐시 미스
        //  -> 캐시가 가득 찬 경우
        //      -> 가장 오래된 캐시 삭제
        if (cacheIter.find(cities[i]) == cacheIter.end())
        {
            if (cache.size() == cacheSize)
            {
                cacheIter.erase(cache.front());
                cache.pop_front();
            }
            time += 5;
        }

        // 캐시 히트
        //  -> 갱신 위해 캐시 삭제
        else
        {
            cache.erase(cacheIter[cities[i]]);
            time += 1;
        }
        cache.push_back(cities[i]);
        cacheIter[cities[i]] = cache.begin();
    }
    return time;
}
