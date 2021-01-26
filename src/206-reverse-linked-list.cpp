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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *p, *r, *dummy;

        // 用例没有头结点, 添加哑结点.
        dummy = new ListNode(0, head);

        p = dummy->next;

        dummy->next = nullptr;

        while (p != nullptr)
        {
            r = p->next;

            p->next = dummy->next;
            dummy->next = p;

            p = r;
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};