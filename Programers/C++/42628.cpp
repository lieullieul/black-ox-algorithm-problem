#include <string>
#include <vector>
#include <deque>

using namespace std;

typedef deque<long long> t_dqLL;

vector<int> solution(vector<string> operations)
{
	t_dqLL dqData;						// 최소값, 최대값 삭제위해 덱 사용
	t_dqLL::iterator it;				// insert 위치 탐색용 이터레이터
	size_t opCnt = operations.size();
    long long param;
    char op;

	for (size_t i = 0; i < opCnt; i++)
	{
		// 명령 문자열 파싱
		op = operations[i][0];
		param = stoll(&operations[i][2]);

		// I
		// 오름차순으로 insert할 위치 찾아서 insert
		if (op == 'I')
		{
			for (it = dqData.begin(); it != dqData.end(); ++it)
			{
				if (param <= *it)
					break;
			}
			dqData.insert(it, param);
		}
		// D
		else
		{
			// 삭제 명령이므로 비어있지 않을 때만 실행
			if (dqData.size())
			{
				if (param == 1)
					dqData.pop_back();
				else
					dqData.pop_front();
			}
		}
	}
	if (dqData.size())
		return { (int)dqData.back(), (int)dqData.front() };
	else
    	return { 0, 0 };
}
