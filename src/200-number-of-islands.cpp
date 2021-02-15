#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int row, int column)
    {
        int rowNum = grid.size();
        int columnNum = grid[0].size();

        // 将已经搜索过的点置为 '0', 确保不会被再次搜索到.
        grid[row][column] = '0';

        if (row - 1 >= 0 && grid[row - 1][column] == '1')
        {
            dfs(grid, row - 1, column);
        }
        if (row + 1 < rowNum && grid[row + 1][column] == '1')
        {
            dfs(grid, row + 1, column);
        }
        if (column - 1 >= 0 && grid[row][column - 1] == '1')
        {
            dfs(grid, row, column - 1);
        }
        if (column + 1 < columnNum && grid[row][column + 1] == '1')
        {
            dfs(grid, row, column + 1);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int rowNum = grid.size();
        if (rowNum == 0)
        {
            return 0;
        }
        int columnNum = grid[0].size();

        int islandNum = 0;
        for (int row = 0; row < rowNum; ++row)
        {
            for (int column = 0; column < columnNum; ++column)
            {
                // 岛屿数量就是连通分量数量.
                if (grid[row][column] == '1')
                {
                    ++islandNum;
                    dfs(grid, row, column);
                }
            }
        }

        return islandNum;
    }
};