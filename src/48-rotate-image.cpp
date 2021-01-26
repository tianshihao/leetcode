#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        auto newMatrix = matrix;
        vector<int> temp(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                newMatrix[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = newMatrix;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution S;

    S.rotate(matrix);

    return 0;
}
