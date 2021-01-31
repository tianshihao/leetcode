#include <vector>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int ans = 0;
        // 获取矩阵行列.
        int rows = matrix.size(), columns = matrix[0].size();
        // 用 dp[i][j] 表示以 (i,j) 为右下角的最大边长正方形.
        // vector 初始化时指定容器大小会将容器中的所有元素初始化为 0.
        vector<vector<int>> dp(rows, vector<int>(columns));

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (matrix[i][j] == 1)
                {
                    if (i == 0 || j == 0)
                    {
                        // 边界条件.
                        dp[i][j] = 1;
                    }
                    else
                    {
                        // 动态规划方程.
                        dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    }
                    // 矩阵中的所有正方形数量等于所有尺寸的正方形数量之和.
                    // dp[i][j] 存储已 (i,j) 为右下角的最大尺寸正方形, 即该尺寸
                    // 的正方形数量, 将所有 dp 中所有元素相加, 即得到了所有尺寸
                    // 的正方形数量之和, 即所有正方形数量之和.
                    ans += dp[i][j];
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}};

    Solution S;
    S.countSquares(matrix);

    return 0;
}
