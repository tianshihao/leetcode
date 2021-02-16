#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        // 左右指针指向窗口的左右边界. 右指针可能指向右边界下一位.
        int left = 0, right = 0;
        // 字符串长度于窗口大小.
        int length = s.length(), windowSize = p.size();

        // 滑动窗口中元素计数和目标字符产计数.
        map<char, int> window, target;
        for (auto ch : p)
        {
            ++target[ch];
        }

        // 由于右指针可能指向右边界下一位, 所以条件为小于等于.
        while (right <= length)
        {
            // 若当前窗口大小小于等于给定窗口大小.
            if (right - left + 1 <= windowSize)
            {
                // 若右指针新指向的元素是合法的元素.
                if (target.count(s[right]))
                {
                    // 则将其计数加 1 并且右指针右移.
                    ++window[s[right++]];
                }
                // 否则.
                else
                {
                    // 跳过不合法的元素.
                    left = ++right;
                    // 清空当前窗口计数.
                    window.clear();
                }
            }
            // 否则右指针指向窗口最大右边界的下一个元素, 即当前窗口大小
            // 为 windowSize + 1.
            else
            {
                // 判断当前窗口计数和目标计数是否相等.
                if (window == target)
                {
                    // 若计数相等, 则将左指针加入答案.
                    ans.push_back(left);

                    // 窗口整体向右滑动.

                    // 左边界右移, 左指针指向的元素计数减 1.
                    --window[s[left++]];
                    // 若计数减为 0, 则丢掉这个元素.
                    if (window[s[left - 1]] == 0)
                    {
                        window.erase(s[left - 1]);
                    }

                    // 由于此时右指针已经指向了右边界的下一个元素,
                    // 因此无需移动右指针.
                }
                // 窗口大小相等, 可能里面元素出现的次数不同, 不符合要求.
                else
                {
                    // 更新左右指针, 重置窗口大小为 1.
                    right = ++left;
                    // 清除当前窗口计数.
                    window.clear();
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution S;

    S.findAnagrams("abab", "ab");

    return 0;
}
