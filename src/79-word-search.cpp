#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<char>> &board, string word,
             vector<vector<int>> visited, int row, int col, int idx)
    {
        // 如果比较到这一步不相等.
        if (board[row][col] != word[idx])
        {
            return false;
        }
        // 比较到这一步相等且比较完毕.
        if (idx == word.size() - 1)
        {
            return true;
        }

        // 访问这个位置.
        visited[row][col] = true;

        // 4 个方向.
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int height = board.size();
        int width = board[0].size();

        bool ans = false;

        for (const auto &dir : directions)
        {
            // 新位置坐标.
            int newRow = row + dir.first, newCol = col + dir.second;

            // 如果新位置坐标合法.
            if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width)
            {
                // 且没有被访问过.
                if (visited[newRow][newCol] == false)
                {
                    // 则沿着这个方向搜索, 如果得到答案则返回 true.
                    if (dfs(board, word, visited, newRow, newCol, idx + 1))
                    {
                        ans = true;
                        break;
                    }
                }
            }
        }

        // 撤销访问.
        visited[row][col] = false;

        return ans;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int height = board.size();
        int width = board[0].size();
        vector<vector<int>> visited(height, vector<int>(width));

        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                // 从单词起始点回溯.
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, visited, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'F'}};

    Solution S;

    S.exist(board, "SEE");

    return 0;
}
