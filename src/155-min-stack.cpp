#include <iostream>

struct Node
{
    int val;
    Node *next;

    Node() {}
    Node(int val) { this->val = val; }
    Node(Node *next) { this->next = next; }
    Node(int val, Node *next)
    {
        this->val = val;
        this->next = next;
    }
};

class MinStack
{
private:
    Node *head;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        head = new Node(nullptr);
    }

    void push(int x)
    {
        Node *newNode = new Node(x, nullptr);

        newNode->next = head->next;
        head->next = newNode;
    }

    void pop()
    {
        Node *p = this->head->next;
        this->head->next = p->next;
        delete p;
    }

    int top()
    {
        return this->head->next->val;
    }

    int getMin()
    {
        Node *p = this->head->next;
        int min = INT32_MAX;

        while (p)
        {
            if (p->val < min)
            {
                min = p->val;
            }
            p = p->next;
        }

        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    std::cout << obj->getMin() << std::endl;
    obj->pop();
    std::cout << obj->top() << std::endl;
    std::cout << obj->getMin() << std::endl;

    return 0;
}
