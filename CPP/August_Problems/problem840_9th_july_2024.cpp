#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool is_valid_magic_square(vector<vector<int>> matrix)
{
    unordered_set<int> set;
    for (const auto &row : matrix)
    {
        for (const auto &element : row)
        {
            set.insert(element);
        }
    }
    unordered_set<int> set_actual = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (set != set_actual)
    {
        return false;
    }
    int req_sum = 0;
    for (int i = 0; i < 3; i += 1)
    {
        req_sum += matrix[0][i];
    }
    for (int i = 1; i < 3; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < 3; j++)
        {
            row_sum += matrix[i][j];
        }
        if (row_sum != req_sum)
        {
            return false;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int col_sum = 0;
        for (int j = 0; j < 3; j++)
        {
            col_sum += matrix[j][i];
        }
        if (col_sum != req_sum)
        {
            return false;
        }
    }
    int diag1_sum = 0;
    for (int i = 0; i < 3; i++)
    {
        diag1_sum += matrix[i][i];
    }
    if (diag1_sum != req_sum)
    {
        return false;
    }
    int diag2_sum = 0;
    for (int i = 0; i < 3; i++)
    {
        diag2_sum += matrix[i][2 - i];
    }
    if (diag2_sum != req_sum)
    {
        return false;
    }
    return true;
}

int numMagicSquaresInside(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int columns = grid[0].size();
    if (rows < 3 or columns < 3)
    {
        return 0;
    }
    else
    {
        int count = 0;
        for (int i = 0; i <= rows - 3; i++)
        {
            for (int j = 0; j <= columns - 3; j++)
            {
                vector<vector<int>> sub_matrix(3, vector<int>(3));
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        sub_matrix[x][y] = grid[i + x][j + y];
                    }
                }
                if (is_valid_magic_square(sub_matrix))
                {
                    count += 1;
                }
            }
        }
        return count;
    }
}

int main()
{
    return 0;
}