#include <iostream>
#include <vector>
using namespace std;

class KthLargest
{
private:
    vector<int> heap;

public:
    // 向下浮动.
    void shiftDown(int root)
    {
        int n = heap.size();

        // 左子结点索引为根结点索引乘以 2.
        for (int child = root << 1; child < n; child <<= 1)
        {
            // 若右子存在且左子小于左子.
            if (child + 1 < n && heap[child] > heap[child + 1])
            {
                // 则选择右子.
                ++child;
            }

            // 若根结点大于较小的子结点.
            if (heap[root] < heap[child])
            {
                // 则什么也不做.
                break;
            }
            // 否则,
            else
            {
                // 交换根结点和子结点.
                swap(heap[root], heap[child]);
                // 同时更新根结点索引, 实现根结点向下浮动.
                root = child;
            }
        }

        return;
    }

    // 向上浮动.
    void shiftUp(int child)
    {
        // 根结点索引为子结点索引除以 2.
        for (int root = child >> 1; root >= 1; root >>= 1)
        {
            // 若根结点小于子结点, 满足小根堆定义.
            if (heap[root] < heap[child])
            {
                // 则什么也不做.
                break;
            }
            // 否则,
            else
            {
                // 交换根结点和子结点.
                swap(heap[root], heap[child]);
                // 同时更新子结点索引, 实现子结点向上浮动.
                child = root;
            }
        }

        return;
    }

    KthLargest(int k, vector<int> &nums)
    {
        // 给小根堆分配
        heap.reserve(k + 1);
        // 填充 0 号元素.
        heap.emplace_back(0);

        for (int num : nums)
        {
            add(num);
        }
    }

    int add(int val)
    {
        if (heap.size() < heap.capacity())
        {
            heap.emplace_back(val);
            // 所以最后一个元素的索引是容器大小减一.
            shiftUp(heap.size() - 1);
        }
        else
        {
            // heap[1] 是最下的元素, 若 val 大于 heap[1], 则更新 heap[1],
            // 确保小根堆中始终保有前 k 个较大元素.
            if (val > heap[1])
            {
                heap[1] = val;
                shiftDown(1);
            }
        }

        return heap[1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
    vector<int> nums = {4, 5, 8, 2};

    KthLargest K(3, nums);

    K.add(3);
    K.add(5);
    K.add(10);
    K.add(9);
    K.add(4);

    return 0;
}
