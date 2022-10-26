#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int getUnplug(std::unordered_set<int> plug, std::vector<int> order, int start)
{
	int ret = 0;
	std::vector<int> dist(101, 0);
	std::vector<int>::iterator	it;
	std::unordered_set<int>::iterator	pit;

	for (pit = plug.begin(); pit != plug.end(); ++pit) {
		int tmp = 1;
		for (it = order.begin() + start + 1; it != order.end(); ++it) {
			if (*it == *pit)
				break;
			tmp++;
		}
		dist[*pit] = tmp;
	}
	int max = 0;
	for (int i = 1; i < 101; ++i) {
		if (max < dist[i]) {
			max = dist[i];
			ret = i;
		}
	}
	return ret;
}

int getTargetIdx(std::unordered_set<int> plug, std::vector<int> order, int start)
{
	int ret = 0;
	std::vector<int>::iterator	it;
	std::unordered_set<int>::iterator	inPlug;

	for (it = order.begin() + start; it != order.end(); ++it) {
		inPlug = std::find(plug.begin(), plug.end(), *it);
		if (inPlug == plug.end())
			break;
		ret++;
	}
	if (it == order.end())
		return -1;
	return start + ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	std::unordered_set<int> plug;
	std::vector<int> order(k, 0);

	for (int i = 0; i < k; ++i)
		std::cin >> order[i];
	int i = 0;
	int cnt = 0;
	bool isValid = true;
	while (cnt < n) {
		isValid = plug.insert(order[i]).second;
		if (isValid == true)
			cnt++;
		i++;
	}

	int target = i;
	int unplug;
	cnt = 0;
	while (true) {
		target = getTargetIdx(plug, order, target);
		if (target == -1)
			break;
		unplug = getUnplug(plug, order, target);
		plug.erase(unplug);
		plug.insert(order[target]);
		target++;
		cnt++;
	}
	std::cout << cnt;
}
