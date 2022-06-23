#include <iostream>
#include <vector>

int	main()
{
	int	n;
	int	m;
	int	rowReq = 0;
	int	colReq = 0;

	std::cin >> n >> m;

	std::vector<int>	row(n, 0);
	std::vector<int>	col(m, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char	c;
			std::cin >> c;
			if (c == 'X')
			{
				row[i]++;
				col[j]++;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (row[i] == 0)
			rowReq++;
	}
	for (int j = 0; j < m; ++j) {
		if (col[j] == 0)
			colReq++;
	}
	std::cout << (rowReq > colReq ? rowReq : colReq);
	return 0;
}
