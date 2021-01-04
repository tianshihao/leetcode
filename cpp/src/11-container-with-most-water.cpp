#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 使用双指针法.
    int maxArea(vector<int> &height)
    {
        // 左右指针.
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while (left < right)
        {
            int tempArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, tempArea);

            // 向内移动较短边的指针.
            // 面积受限于底边和两条竖边中的较短边, 向内移动指针一定会缩短底边,
            // 但是有可能使竖边中的某一边增大, 从而面积也增大, 所以移动较短边的
            // 指针合理.
            if (height[left] <= height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return maxArea;
    }
};

int main()
{
    vector<int> height = {1, 2, 1};

    Solution S;

    cout << S.maxArea(height) << endl;

    return 0;
}
