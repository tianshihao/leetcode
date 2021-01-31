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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        // 添加哑结点.
        ListNode *dummy = new ListNode(-1, head);
        // 工作指针 p 指向第一个结点. tail 指向已排好序的链表尾结点.
        ListNode *p = dummy->next, *tail;
        // 指针 r 保存 p 的后继.
        ListNode *r = p->next;

        // 断开第一个结点的后继, 相当于先构造了只有一个结点的有序链表.
        p->next = nullptr;

        // 更新工作结点.
        p = r;

        // p 不为空指针时, 进行插入排序.
        while (p != nullptr)
        {
            // 先记录工作指针后继.
            r = p->next;

            // tail 从头结点开始.
            tail = dummy;

            // 寻找合适的插入位置.
            while (tail->next != nullptr && tail->next->val < p->val)
            {
                tail = tail->next;
            }

            // 将 p 插入到 tail 之后
            p->next = tail->next;
            tail->next = p;

            // 读取之前记录的后继.
            p = r;
        }

        // 保存答案.
        p = dummy->next;

        // 释放内存.
        delete dummy;

        return p;
    }
};
