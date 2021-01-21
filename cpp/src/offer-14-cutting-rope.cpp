#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::max;
using std::vector;

class Solution
{
public:
    //n >= 5 2*(n-2) > n   3*(n-3) > n  且3*(n-3) >= 2*(n-2)
    //n = 4 2 * 2 > 1 * 3
    //2和3不能再分了  分了就变小了 且3优于2
    int cuttingRope(int n)
    {
        if (n <= 3)
            return n - 1;
        long ans = 1;
        while (n > 4)
        {
            // 3最优
            ans *= 3;
            ans %= 1000000007;
            n -= 3;
        }
        //循环结束 n只剩下1, 2 ,3,4
        //1不能再分
        //2，3再分会标小
        //4 可以分成1 * 3  2 * 2,所以还是4最优
        //所以 剩下的1 2 3 4 都不能再分了
        return (ans * n) % 1000000007;
    }
};

int main()
{
    Solution S;
    cout << S.cuttingRope(120) << endl;

    return 0;
}
