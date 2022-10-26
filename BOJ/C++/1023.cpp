#include <iostream>
#include <stack>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	char str[51];
	long long n, k;
	long long cnt = 0;
	bool valid = true;

	std::cin >> n >> k;
	long long size = n;
	long long tmp;
	str[size] = 0;
	for (long long i = 0; cnt < std::pow(2, k); ++i) {
		std::stack<char> st;
		n = size - 1;
		tmp = i;
		while (n >= 0) {
			str[n] = tmp % 2 + '(';
			if (str[n] == '(')
				st.push('(');
			else {
				if (st.top() == '(')
					st.pop();
				else
					break;
			}
			tmp /= 2;
			n--;
		}
		cnt++;
	}
	// if (k % 2 == 0 && pre == post)
	// 	std::cout << -1;
	// else
		std::cout << str;
	return 0;
}
