#include <iostream>

int dig(int n)
{
	int ret = 0;

	while (n > 0)
	{
		ret += n % 10;
		n /= 10;
	}
	if (ret >= 10)
		ret = dig(ret);
	return ret;
}

void caseSquare(int k, int m)
{
	k %= 4;
	switch (k)
	{
	case 1:
		std::cout << "0 1\n";
		break;
	case 2:
		std::cout << m << " 1\n";
		break;
	case 3:
		std::cout << m << " 0\n";
		break;
	case 0:
		std::cout << "0 0\n";
		break;
	}
}

void caseLoopCycle1(int k, int m)
{
	k %= 4;
	switch (k)
	{
	case 1:
		std::cout << -(9 - m) << " 1\n";
		break;
	case 2:
		std::cout << m << " 1\n";
		break;
	case 3:
		std::cout << m << " -8\n";
		break;
	case 0:
		std::cout << -(9 - m) << " -8\n";
		break;
	}
}

void caseLoopCycle2(int k, int m)
{
	int x = 0;
	int y = 0;
	int nowDig = 1;
	int sign = 1;

	k %= 12;
	if (k == 0)
		k = 12;
	for (int i = 1; i <= k; ++i) {
		if (((i - 1) % 4) / 2 == 0)
			sign = 1;
		else
			sign = -1;
		if (i % 2 == 1)
			y = y + sign * nowDig;
		else
			x = x + sign * nowDig;
		nowDig = dig(nowDig * m);
	}
	std::cout << x << ' ' << y << '\n';
}

void printCoordinate(int k, int m)
{
	if (k == 1)
	{
		std::cout << "0 1\n";
		return;
	}
	m = dig(m);
	if (m == 1 || m == 8)
		caseSquare(k, m);
	else if (m % 3 == 0)
		caseLoopCycle1(k, m);
	else
		caseLoopCycle2(k, m);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int inp;
	int k, m;

	std::cin >> inp;
	for (int i = 0; i < inp; ++i)
	{
		std::cin >> k >> m;
		printCoordinate(k, m);
	}
	return 0;
}
