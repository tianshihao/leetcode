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
    ListNode *swapPairs(ListNode *head)
    {
        // 新增哑结点.
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *temp = dummyHead;

        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            ListNode *node1 = temp->next;
            ListNode *node2 = temp->next->next;
            // 交换 temp 后的两个结点.
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            // 更新 temp, 此时 node 相当于之前的 dummy.
            temp = node1;
        }

        return dummyHead->next;
    }
};