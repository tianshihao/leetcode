#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Solution
{
public:
    int quickSort(vector<int> &nums, int low, int high, int index)
    {
        int pivotPos = randomPartition(nums, low, high);

        // 第 k 大的元素的索引是 index == heapSize - k.
        if (pivotPos == index)
        {
            return nums[pivotPos];
        }
        else
        {
            // 如果得到的枢轴的位置比目标小, 就递归右子区间, 否则反之.
            return pivotPos < index ? quickSort(nums, pivotPos + 1, high, index) : quickSort(nums, low, pivotPos - 1, index);
        }
    }

    int randomPartition(vector<int> &nums, int low, int high)
    {
        int i = rand() % (high - low + 1) + low;
        swap(nums[low], nums[i]);
        return partition(nums, low, high);
    }

    int partition(vector<int> &nums, int low, int high)
    {
        // 将划分区间的第一个元素作为枢轴.
        int pivot = nums[low];

        while (low < high)
        {
            // 从右端开始把比枢轴小的元素移动到左端.
            while (low < high && nums[high] >= pivot)
            {
                --high;
            }
            nums[low] = nums[high];

            // 从左端开始比把枢轴大的元素移动到右端.
            while (low < high && nums[low] <= pivot)
            {
                ++low;
            }
            nums[high] = nums[low];
        }

        // 把枢轴放到合适的位置上.
        nums[low] = pivot;

        // 返回最终存放枢轴的位置.
        return low;
    }

    void buildMaxHeap(vector<int> &nums, int heapSize)
    {
        for (int i = heapSize / 2; i >= 0; --i)
        {
            heapAdjust(nums, i, heapSize);
        }
        return;
    }

    void heapAdjust(vector<int> &nums, int root, int heapSize)
    {
        // 暂存根结点.
        int tmp = nums[root];

        // 检查根结点的左右子.
        for (int child = 2 * root + 1; child < heapSize; child = child * 2 + 1)
        {
            // 若右子大于左子, 则选取右子.
            if (child + 1 < heapSize && nums[child] < nums[child + 1])
            {
                ++child;
            }

            // 若根结点大于较大子结点.
            if (tmp >= nums[child])
            {
                // 则什么也不做.
                break;
            }
            // 否则,
            else
            {
                // 将较大子结点的值赋给根结点.
                nums[root] = nums[child];
                // 更新根结点为较大子结点.
                root = child;
            }
        }
        nums[root] = tmp;
        return;
    }

    int heapSort(vector<int> &nums, int k)
    {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = heapSize - 1; i >= heapSize - k + 1; --i)
        {
            swap(nums[0], nums[i]);
            heapAdjust(nums, 0, i);
        }
        return nums[0];
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        // srand(time(0));
        // return quickSort(nums, 0, nums.size() - 1, nums.size() - k);

        return heapSort(nums, k);
    }
};

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6};

    Solution S;
    S.findKthLargest(nums, 2);

    return 0;
}
