struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 添加哑结点.
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // 设置快慢指针.
        ListNode *slow = dummy, *fast = dummy;

        // 注意循环条件.
        while (slow != nullptr && fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            /* 快慢指针相遇. */
            if (slow == fast)
            {
                break;
            }
        }

        // 注意判断条件. 没有环.
        if (slow == nullptr || fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }

        ListNode *p1 = dummy;
        ListNode *p2 = slow;

        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};
