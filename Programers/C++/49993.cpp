#include <string>
#include <vector>

using namespace std;

// 49993 스킬트리
// https://school.programmers.co.kr/learn/courses/30/lessons/49993

int solution(string skill, vector<string> skill_trees) {
    int skillSize = skill.size();
    int treeSize = skill_trees.size();
    int answer = 0;

    // 스킬 트리 순회
    for (int i = 0; i < treeSize; i++)
    {
        int order = 0;
        bool bPossible = true;
        string& tree = skill_trees[i];

        // 각 트리 순회
        for (int j = 0; j < tree.size(); j++)
        {
            // 스킬마다 스킬트리와 비교
            for (int k = 0; k < skillSize; k++)
            {
                // 스킬 트리에 있는 스킬
                if (skill[k] == tree[j])
                {
                    // 이전 스킬을 배우지 않았다면 불가능
                    if (k != order)
                    {
                        bPossible = false;
                        break;
                    }
                    else
                        order++;
                }
            }
        }
        if (bPossible)
            answer++;
    }

    return answer;
}
