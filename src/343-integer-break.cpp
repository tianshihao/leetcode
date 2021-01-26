class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        if (n == 3)
        {
            return 2;
        }
        vector<int> ans(n + 1);
        ans[1] = 1;
        ans[2] = 2;
        ans[3] = 3;
        for (int i = 4; i <= n; ++i)
        {
            ans[i] = max(2 * ans[i - 2], 3 * ans[i - 3]);
        }

        return ans[n];
    }
};