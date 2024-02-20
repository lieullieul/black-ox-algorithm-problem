#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 2402
// https://leetcode.com/problems/meeting-rooms-iii

// 빈 방, 사용중인 방 우선순위 큐 관리
// meetings 시작 순서대로 정렬
// 빈 방이 없으면 가장 일찍 끝나는 방 정리
// 회의 시작 시간과 가장 일찍 끝나는 시간 중 늦은 시간 기준으로 방 사용

class Solution {
public:
    class CRoom
    {
    public:
        long long _end;
        int _room;

        CRoom(long long end, int room) : _end(end), _room(room) {}

        bool operator<(const CRoom& rhs) const
        {
            if (this->_end == rhs._end)
            {
                return this->_room > rhs._room;
            }
            return this->_end > rhs._end;
        }
    };

    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> freeRoom;
        priority_queue<CRoom> useRoom;
        vector<int> cnt(n, 0);
        int size = meetings.size();

        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < n; i++)
        {
            freeRoom.push(i);
        }

        long long  end;
        int room;
        for (int idx = 0; idx < size; idx++)
        {
            end = meetings[idx][0];
            while (!useRoom.empty() && useRoom.top()._end <= meetings[idx][0])
            {
                if (useRoom.top()._end < end)
                    end = useRoom.top()._end;
                room  = useRoom.top()._room;
                freeRoom.push(room);
                useRoom.pop();
            }

            if (freeRoom.empty())
            {
                end = useRoom.top()._end;
                room = useRoom.top()._room;
                freeRoom.push(room);
                useRoom.pop();
            }

            room = freeRoom.top();
            freeRoom.pop();
            long long start = end > meetings[idx][0] ? end : meetings[idx][0];
            useRoom.push({start + meetings[idx][1] - meetings[idx][0], room});
            cnt[room]++;
        }

        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};
