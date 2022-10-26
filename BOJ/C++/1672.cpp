#include <iostream>
#include <string>
#include <map>

int main()
{
	int	inp;
	std::string	str;
	std::map<std::pair<char, char>, char>	m;

	m.insert(std::make_pair(std::make_pair('A', 'A'), 'A'));
	m.insert(std::make_pair(std::make_pair('A', 'G'), 'C'));
	m.insert(std::make_pair(std::make_pair('A', 'C'), 'A'));
	m.insert(std::make_pair(std::make_pair('A', 'T'), 'G'));

	m.insert(std::make_pair(std::make_pair('G', 'A'), 'C'));
	m.insert(std::make_pair(std::make_pair('G', 'G'), 'G'));
	m.insert(std::make_pair(std::make_pair('G', 'C'), 'T'));
	m.insert(std::make_pair(std::make_pair('G', 'T'), 'A'));

	m.insert(std::make_pair(std::make_pair('C', 'A'), 'A'));
	m.insert(std::make_pair(std::make_pair('C', 'G'), 'T'));
	m.insert(std::make_pair(std::make_pair('C', 'C'), 'C'));
	m.insert(std::make_pair(std::make_pair('C', 'T'), 'G'));

	m.insert(std::make_pair(std::make_pair('T', 'A'), 'G'));
	m.insert(std::make_pair(std::make_pair('T', 'G'), 'A'));
	m.insert(std::make_pair(std::make_pair('T', 'C'), 'G'));
	m.insert(std::make_pair(std::make_pair('T', 'T'), 'T'));

	std::cin >> inp;
	std::cin >> str;

	while (str.length() > 1) {
		int	pre = str.length() - 2;
		int	last = str.length() - 1;

		str[pre] = m[std::make_pair(str[pre], str[last])];
		str.pop_back();
	}
	std::cout << str;

	return 0;
}
