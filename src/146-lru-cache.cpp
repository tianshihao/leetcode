#include <unordered_map>
using namespace std;

struct DLinkedNode
{
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int _size;
    int _capacity;

public:
    LRUCache(int capacity) : _capacity(capacity), _size(0)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        // 如果关键字不存在.
        if (!cache.count(key))
        {
            return -1;
        }

        // 如果关键字存在
        DLinkedNode *node = cache[key];
        // 则将结点移动到双向链表头部.
        moveToHead(node);
        // 返回关键字的值.
        return node->value;
    }

    void put(int key, int value)
    {
        // 如果 key 不存在.
        if (!cache.count(key))
        {
            // 创建一个新的结点.
            DLinkedNode *node = new DLinkedNode(key, value);
            // 添加进哈希表.
            cache[key] = node;
            // 添加至双向链表的头部.
            addToHead(node);
            // 链表加一.
            ++_size;
            // 如果超出容量.
            if (_size > _capacity)
            {
                // 删除双向链表的尾部节点.
                DLinkedNode *removed = removeTail();
                // 删除哈希表中对应的项.
                cache.erase(removed->key);
                // 释放内存空间, 防止内存泄漏.
                delete removed;
                // 链表大小减一.
                --_size;
            }
        }
        // 如果 key 存在.
        else
        {
            // 先通过哈希表定位.
            DLinkedNode *node = cache[key];
            // 再修改 value.
            node->value = value;
            // 并移动到头部.
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */