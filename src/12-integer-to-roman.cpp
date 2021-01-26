#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        unordered_map<int, char> occ = {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}};

        string ans;
        int mod = 10;

        // 罗马数字可分为 3 类, 3 个倍率.
        // 1x   5x  10x
        // I    V   X
        // X    L   C
        // C    D   M

        // 由于是从末尾向高位分析, 因此 ans 是答案的逆序, 最后需要反转.
        while (num != 0)
        {
            // 弹出的末尾数字.
            int pop = num % mod;
            // 更新原数字, 以便在下一次取 % (mod * 10) 时得到想要的结果.
            num -= pop;
            // 倍率. 由于循环 x 依次取值 1, 10, 100, 1000.
            // 乘以相应的数字后可以在 unordered_map 中找到对应的键值.
            // 1x, 1 : 'I', 10 : 'X', 100 : 'C', 1000 : 'M'.
            // 5x, 5 : 'V', 50 : 'L', 500 : 'D'.
            int x = mod / 10;

            // 4, 40, 400, IV, XL, CD
            // 4x, 特殊, 5x + 1x.
            if (pop == 4 * x)
            {
                ans += occ[5 * x];
                ans += occ[x];
            }
            // 9, 90, 900, IX, XC, CM
            // 9x, 特殊, 10x + 1x
            else if (pop == 9 * x)
            {
                ans += occ[10 * x];
                ans += occ[x];
            }
            // 1, 2, 3, 10, 20, 30, 100, 200, 300, 1000, 2000, 3000
            // I, II, III, X, XX, XXX, C, CC, CCC, M, MM, MMM
            // 1x:3x, 1xs.
            else if (pop <= 3 * x)
            {
                // 在 x == 1 时, 使用 while(pop--)
                // 但这不能满足 x == 10 或 x == 100 等情况, 需要改成
                // while(pop -= x), 但该语句是先运算后判断, 不是先判断后运算的 pop--,
                // 所以需要 pop += x 让循环可以进行下去.
                pop += x;
                while (pop -= x)
                {
                    ans += occ[x];
                }
            }
            // 5, 6, 7, 8, 50, 60, 70, 80, 500, 600, 700, 800
            // 5x:8x, 1xs + 5x.
            else
            {
                // 处理重复的 1x
                pop -= (5 * x);

                pop += x;
                while (pop -= x)
                {
                    ans += occ[x];
                }
                // 加上 5x.
                ans += occ[5 * x];
            }

            // 更新 mod.
            mod *= 10;
        }

        // 注意, 上述算法取得是逆序, 需要反转字符串.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution S;

    cout << S.intToRoman(58) << endl;

    return 0;
}
