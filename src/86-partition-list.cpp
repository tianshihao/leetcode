
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small = new ListNode(0);
        // smallHead 和 largeHead 指向 small 和 large 的头结点.
        ListNode *smallHead = small;
        ListNode *large = new ListNode(0);
        ListNode *largeHead = large;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        // large 表尾置空.
        large->next = nullptr;
        // small 的尾结点指向 large 的第一个结点.
        small->next = largeHead->next;
        // 返回 small 的第一个结点.
        return smallHead->next;
    }
};
