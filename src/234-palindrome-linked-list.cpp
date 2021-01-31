
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
    bool isPalindrome(ListNode *head)
    {
        // 特判, 0 个结点和 1 个结点.
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }

        // 快慢指针.
        ListNode *slow = head, *fast = head;

        // 循环遍历结束后 slow 指向第 n / 2 个结点.
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 逆置后半部分.
        ListNode *q = slow->next;
        ListNode *r = q->next;

        // slow 相当于逆置后半段链表时的头结点, 将其后继置为空.
        slow->next = nullptr;

        // 逆置后半段链表.
        while (q)
        {
            // 保存后继.
            r = q->next;

            // 头插法.
            q->next = slow->next;
            slow->next = q;

            // 读取后继.
            q = r;
        }

        // p 和 q 分别指向链表前半段和后半段的开始.
        ListNode *p = head;
        q = slow->next;

        // 比较两段链表.
        while (p && q)
        {
            if (p->val != q->val)
            {
                return false;
            }
            p = p->next;
            q = q->next;
        }

        return true;
    }
};

int main()
{
    ListNode *fourth = new ListNode(1);
    ListNode *third = new ListNode(0);
    ListNode *second = new ListNode(0, third);
    ListNode *first = new ListNode(1, second);

    Solution S;
    S.isPalindrome(first);

    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
