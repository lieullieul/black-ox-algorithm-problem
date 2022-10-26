#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

int getMin(int size, int layer)
{
	if (layer == 1)
		return 1;

	int totalLayer = size % 2 ? size / 2 + 1 : size / 2;
	int ret = totalLayer - layer;
	int	max = size * size;
	ret = (ret * (ret + 1)) / 2;
	if (size % 2)
		ret = max - (ret * 8);
	else
		ret = max - 3 - (ret * 8) - ((totalLayer - layer) * 4);
	return ret;
}

int getLayer(int size, int z)
{
	int totalLayer = size % 2 ? size / 2 + 1 : size / 2;
	int max = size * size;
	int layer;

	if (max == z)
		return totalLayer;
	if (size % 2) {
		int c = ((max - 1 - z) / 4) * -1;
		double tmp = std::sqrt(1 - (c * 4));
		double x;

		x = (-1 + tmp) / 2;
		if (x < 0)
			x = (-1 - tmp) / 2;
		layer = totalLayer - static_cast<int>(std::floor(x)) - 1;
	}
	else
		layer = totalLayer - static_cast<int>(std::floor(std::sqrt(((max - z) / 4))));
	return layer;
}

void execQuery(int flag, int size, int x, int y, int z)
{
	if (flag == 1) {
		int layer = std::min(std::min(size - x + 1, x), std::min(size - y + 1, y));
		int min = getMin(size, layer);
		int max = min + ((size - (layer * 2) + 1) * 4) - 1;

		if (x == layer || y == size - layer + 1)
			printf("%d\n", min + x + y - (layer * 2));
		else if (x == size - layer + 1 || y == layer)
			printf("%d\n",max - x - y + 1 + (layer * 2));
	}
	else {
		int layer = getLayer(size, z);
		int min = getMin(size, layer);
		int max = min + ((size - (layer * 2) + 1) * 4) - 1;
		int mid = (min + max) / 2 + 1;

		if (z <= mid) {
			if (z <= (min + mid) / 2)
				printf("%d %d\n",layer, z - min + layer);
			else
				printf("%d %d\n", z - (min + mid) / 2 + layer, size - layer + 1);
		}
		else {
			if (z <= (mid + max) / 2 + 1)
				printf("%d %d\n", size - layer + 1, (mid + max) / 2 + 1 - z + layer);
			else
				printf("%d %d\n", max - z + layer + 1, layer);
		}
	}
}

int main()
{
	int q;
	int flag[100000];
	int n[100000];
	int x[100000];
	int y[100000];
	int z[100000];

	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		scanf("%d", &flag[i]);
		if (flag[i] == 1)
			scanf("%d %d %d", &n[i], &x[i], &y[i]);
		else
			scanf("%d %d", &n[i], &z[i]);
	}
	for (int i = 0; i < q; ++i)
		execQuery(flag[i], n[i], x[i], y[i], z[i]);
	return 0;
}
