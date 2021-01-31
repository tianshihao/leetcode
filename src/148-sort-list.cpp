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
    // 归并排序.
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }

        // 计算链表长度.
        int length = 0;
        ListNode *p = head;
        while (p != nullptr)
        {
            ++length;
            p = p->next;
        }

        // 添加哑结点.
        ListNode *dummyHead = new ListNode(0, head);

        for (int subLength = 1; subLength < length; subLength <<= 1)
        {
            // 指针 sorted 指向归并一趟之后得到的有序链表的尾结点, 初始指向头结点.
            // 指针 cur 是工作结点. 每次进入循环时指向未还没有归并的结点.
            ListNode *sorted = dummyHead, *cur = dummyHead->next;

            // 分割链表. 每次拿出前两个长度为 subLength 的子链表, 归并这两个
            // 子链表.
            while (cur != nullptr)
            {
                // 指针 head1 指向待归并的第一个子链表.
                ListNode *head1 = cur;

                // 数 subLength 个结点给第一个子链表.
                for (int i = 1; i < subLength && cur->next != nullptr; i++)
                {
                    cur = cur->next;
                }

                // 指针 head2 指向紧接着第一个子链表待归并的第二个子链表.
                ListNode *head2 = cur->next;

                // 将第一个子链表的末尾断开, 此时将第一个子链表分割了出来.
                cur->next = nullptr;

                // 更新工作指针.
                cur = head2;

                // 再数 subLength 结点.
                for (int i = 1; i < subLength && cur != nullptr && cur->next != nullptr; i++)
                {
                    cur = cur->next;
                }

                // 指针 rest 剩余链表.
                ListNode *rest = nullptr;

                // 此时 cur 指向第二个子链表的尾结点. 如果此时 cur 不为空,
                // 则表示还有剩余链表结点.
                if (cur != nullptr)
                {
                    // 记录剩余链表的头结点,
                    rest = cur->next;
                    // 将第二个子链表尾结点断开.
                    cur->next = nullptr;
                }

                // 至此得到两个长度为 subLength 的子链表, 合并两个子链表.
                ListNode *merged = merge(head1, head2);

                // 更新已排序链表. 将上一趟已归并的末尾断开的子链表和这一趟归并
                // 得到的子链表串起来.
                sorted->next = merged;
                while (sorted->next != nullptr)
                {
                    sorted = sorted->next;
                }

                // 更新工作指针将其指向剩余链表.
                cur = rest;
            }
        }

        // 保存结果.
        p = dummyHead->next;

        // 释放内存.
        delete dummyHead;

        return p;
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        // 添加哑结点.
        ListNode *dummyHead = new ListNode(0);
        // 工作指针 p 指向已合并得到的链表尾结点, p1 和 p2 指向待合并的链表.
        ListNode *p = dummyHead, *p1 = head1, *p2 = head2;

        while (p1 != nullptr && p2 != nullptr)
        {
            // 将合适的结点插入到 p 之后
            if (p1->val <= p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }

        // 若某一链表有剩余结点.
        if (p1 != nullptr)
        {
            p->next = p1;
        }
        else if (p2 != nullptr)
        {
            p->next = p2;
        }

        // 保存结点.
        p = dummyHead->next;

        // 释放内存.
        delete dummyHead;

        return p;
    }
};
