#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        if (head == nullptr)
        {
            return {};
        }

        vector<int> ans = reversePrint(head->next);
        ans.push_back(head->val);
        return ans;
    }
};

int main()
{
    ListNode *node3 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node1 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;

    Solution S;

    S.reversePrint(node1);

    return 0;
}
