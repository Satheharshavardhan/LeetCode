#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
{
    vector<vector<int>> result;
    vector<int> directions = {0, 1, 0, -1, 0};
    int step_size = 1;
    int direction = 0;
    result.push_back({rStart, cStart});
    int count_elements = rows * cols - 1;
    while (count_elements > 0)
    {
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < step_size; j += 1)
            {
                rStart += directions[direction];
                cStart += directions[direction + 1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                {
                    result.push_back({rStart, cStart});
                    count_elements -= 1;
                }
            }
            direction = (direction + 1) % 4;
        }
        ++step_size;
    }
    return result;
}

int main()
{
    int rows = 1, cols = 4, rStart = 0, cStart = 0;
    vector<vector<int>> visited_positions = spiralMatrixIII(rows, cols, rStart, cStart);
    for (const auto &point : visited_positions)
    {
        cout << "(" << point[0] << " " << point[1] << ")" << endl;
    }
    return 0;
}
