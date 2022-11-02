#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<vector<string> > g_setPossibleCase;
vector<string> g_tmpBanlist;
vector<string> g_vecBanlist;
vector<bool>  g_visit;

bool compare(const string& user_id, const string& bannned_id)
{
	if (user_id.size() != bannned_id.size())
		return true;
	for (size_t i = 0; i < user_id.size(); i++)
	{
		if (bannned_id[i] != user_id[i] && bannned_id[i] != '*')
			return true;
	}
	return false;
}

void setCaseRecursive(size_t depth, const vector<string>& user_id, const vector<string>& banned_id)
{
	if (depth == banned_id.size())
	{
		g_tmpBanlist = g_vecBanlist;
		sort(g_tmpBanlist.begin(), g_tmpBanlist.end());
		g_setPossibleCase.insert(g_tmpBanlist);
		return ;
	}
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
	g_visit.resize(user_id.size(), false);
	setCaseRecursive(0, user_id, banned_id);
	return g_setPossibleCase.size();
}

int main()
{
	vector<string> str1 = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> str2 = { "*rodo", "*rodo", "******" };
	solution(str1, str2);
}
