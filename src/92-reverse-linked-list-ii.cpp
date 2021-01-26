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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == n)
        {
            return head;
        }

        // 添加哑结点.
        ListNode *dummy = new ListNode(0, head);
        // 让头结点变成头结点/
        head = dummy;
        // pn 指向第 n 个结点的后继. 初始指向头结点.
        ListNode *pn = head;
        // 所以计数器初值为 0.
        int count = 0;

        // 让 head 指向第 m - 1 个结点.
        while (count < m - 1)
        {
            head = head->next;
            pn = pn->next;
            ++count;
        }

        // 继续计数, 让 pn 指向第 n 个结点的后继.
        while (count <= n)
        {
            pn = pn->next;
            ++count;
        }

        // head 指向第 m - 1 个结点, 相当于子链表 m->n 的"头结点".
        // p 是工作指针, 初始指向第 m 个结点.
        ListNode *p = head->next;
        // 指针 r 保存 p 的后继.
        ListNode *r = p->next;

        // 将头结点剥离出来, 这里的 pn 就相当于一般的链表逆置中的 nullptr.
        head->next = pn;

        while (r != pn)
        {
            // 更新后继.
            r = p->next;

            // 用头插法将结点插入头结点之后, 实现逆置.
            p->next = head->next;
            head->next = p;

            // 工作指针指向下一个结点.
            p = r;
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};

int main()
{
    ListNode fifth(5);
    ListNode fourth(4, &fifth);
    ListNode third(3, &fourth);
    ListNode second(2, &third);
    ListNode first(1, &second);

    Solution S;
    S.reverseBetween(&first, 2, 4);

    return 0;
}
