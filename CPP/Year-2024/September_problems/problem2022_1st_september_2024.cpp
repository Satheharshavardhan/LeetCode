#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
{
    if (original.size() != m * n)
    {
        return {};
    }
    vector<vector<int>> two_D_array(m, vector<int>(n));
    for (int i = 0; i < m; i += 1)
    {
        for (int j = 0; j < n; j += 1)
        {
            two_D_array[i][j] = original[i * n + j];
        }
    }
    return two_D_array;
}

int main()
{
    return 0;
}