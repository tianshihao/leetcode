#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        // 特判. 如果矩阵为空, 返回 false.
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }

        int row = 0;
        int column = matrix[0].size() - 1;

        while (row < matrix.size() && column >= 0)
        {
            if (matrix[row][column] > target)
            {
                column--;
            }
            else if (matrix[row][column] == target)
            {
                return true;
            }
            else
            {
                row++;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    Solution S;

    if (S.findNumberIn2DArray(matrix, -1))
    {
        cout << "found\n";
    }
    else
    {
        cout << "not found\n";
    }

    return 0;
}
