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
    int getLength(ListNode *head)
    {
        int length = 0;
        while (head)
        {
            ++length;
            head = head->next;
        }
        return length;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 添加哑结点.
        ListNode *dummy = new ListNode(0, head);
        // 获取链表长度.
        int length = getLength(head);
        // 游标.
        ListNode *cur = dummy;

        for (int i = 0; i < length - n; ++i)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main()
{
    // ListNode *node5 = new ListNode(5);
    // ListNode *node4 = new ListNode(4, node5);
    // ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2);
    ListNode *node1 = new ListNode(1, node2);

    Solution S;
    ListNode *ans = S.removeNthFromEnd(node1, 1);

    return 0;
}
