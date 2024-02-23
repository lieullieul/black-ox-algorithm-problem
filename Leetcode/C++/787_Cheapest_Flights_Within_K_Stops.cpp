#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 787. Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops

// 지금까지 온 거리, 현재 위치
// k 만큼 bfs 탐색
class Solution {
	typedef int t_Now;
	typedef int t_Price;
	typedef int t_Src;
	typedef int t_Dst;

	struct StData
	{
		int stop;
		int now;
		int price;
	};

public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<t_Price> visit(n, 0x7FFFFFFF);
		vector<vector<pair<t_Dst, t_Price>>> vvPrice(n);
		queue<StData> q;

		for (auto v : flights)
		{
			vvPrice[v[0]].push_back({ v[1], v[2] });
		}

		q.push({ 0, src, 0 });
		visit[src] = 0;
		while (!q.empty())
		{
			StData d = q.front();
			q.pop();

			for (auto pr : vvPrice[d.now])
			{
				int nextNow = pr.first;
				int nextPrice = pr.second + d.price;
				//
				if (nextPrice < visit[nextNow])
				{
					visit[nextNow] = nextPrice;
					if (d.stop < k)
						q.push({ d.stop + 1, nextNow, nextPrice });
				}

			}
		}
		if (visit[dst] == 0x7FFFFFFF)
			return -1;
		return visit[dst];
	}
};
