// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0;
        int up = 0;
        ListNode* cur = nullptr;
        ListNode* ret;

        while (up || l1 || l2)
        {
            int num1 = l1 == nullptr ? 0 : l1->val;
            int num2 = l2 == nullptr ? 0 : l2->val;
            sum = num1 + num2 + up;
            if (sum >= 10)
            {
                sum -= 10;
                up = 1;
            }
            else
                up = 0;

            ListNode* pNew = new ListNode(sum);
            if (cur == nullptr)
            {
                cur = pNew;
                ret = cur;
            }
            else
            {
                cur->next = pNew;
                cur = pNew;
            }

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return ret;
    }
};
