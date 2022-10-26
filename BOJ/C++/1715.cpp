#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	int inp;
	int sum = 0;
	int a, b;
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> inp;
		q.push(inp);
	}
	while (q.size() > 1) {
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		q.push(a + b);
		sum += a + b;
	}
	std::cout << sum << std::endl;
	return 0;
}
