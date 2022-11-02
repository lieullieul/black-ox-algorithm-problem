#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<vector<string> > g_setPossibleCase;
vector<string> g_tmpBanlist;
vector<string> g_vecBanlist;
vector<bool>  g_visit;

// 문자열 비교 함수
bool compare(const string& user_id, const string& bannned_id)
{
	// 두 문자열 길이가 다른 경우 true
	if (user_id.size() != bannned_id.size())
		return true;

	// 같으면 계속 반복
	// 다른데 * 아니면 true
	for (size_t i = 0; i < user_id.size(); i++)
	{
		if (bannned_id[i] == user_id[i])
			continue;
		if (bannned_id[i] != '*')
			return true;
	}
	return false;
}

// DFS
// 조건을 만족하는 모든 경우의 수 탐색
// 중복 케이스 제거 위해 임시 벡터에 저장 후 정렬해서 셋에 삽입
// 어떤 컨테이너를 사용할 것인가?
void setCaseRecursive(size_t depth, const vector<string>& user_id, const vector<string>& banned_id)
{
	// 탈출 조건
	// 임시 벡터에 옮겨담고 정렬 후 set에 삽입
	if (depth == banned_id.size())
	{
		g_tmpBanlist = g_vecBanlist;
		sort(g_tmpBanlist.begin(), g_tmpBanlist.end());
		g_setPossibleCase.insert(g_tmpBanlist);
		return ;
	}

	// 유저 아이디 재귀 탐색
	// 밴 목표 아이디와 같다면
	// 벡터에 값 넣고 방문 체크하고 재귀 호출
	// 복귀 시 초기화
	for (size_t i = 0; i < user_id.size(); i++)
	{
		if (g_visit[i] == false)
		{
			if (!compare(user_id[i], banned_id[depth]))
			{
				g_vecBanlist.push_back(user_id[i]);
				g_visit[i] = true;
				setCaseRecursive(depth + 1, user_id, banned_id);
				g_vecBanlist.pop_back();
				g_visit[i] = false;
			}
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id)
{
	// 전역변수 할당 및 초기화
	g_tmpBanlist.reserve(banned_id.size());
	g_vecBanlist.reserve(banned_id.size());
	g_visit.resize(user_id.size(), false);

	setCaseRecursive(0, user_id, banned_id);
	return g_setPossibleCase.size();
}
