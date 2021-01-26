class Solution
{
public:
    int climbStairs(int n)
    {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i)
        {
            // 状态转移方程 f(x) = f(x - 1) + f(x - 2)
            p = q;     // f(x-1)
            q = r;     // f(x-2)
            r = p + q; // f(x)
        }
        return r;
    }
};

int main()
{
    return 0;
}
