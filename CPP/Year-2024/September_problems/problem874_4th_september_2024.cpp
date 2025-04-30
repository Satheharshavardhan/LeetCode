#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct pair_hash
{
    inline size_t operator()(const pair<int, int> &v) const
    {
        return v.first * 31 + v.second;
    }
};

bool is_obstacles(int x, int y, unordered_set<pair<int, int>, pair_hash> &obstacles_set)
{
    return obstacles_set.find({x, y}) != obstacles_set.end();
}

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    unordered_set<pair<int, int>, pair_hash> obstacles_set;
    for (const auto &obs : obstacles)
    {
        obstacles_set.insert({obs[0], obs[1]});
    }
    int current_dir = 0;
    int current_x = 0, current_y = 0;
    int max_distance = 0;

    for (const auto &command : commands)
    {
        if (command == -2)
        {
            current_dir = (current_dir + 3) % 4;
        }
        else if (command == -1)
        {
            current_dir = (current_dir + 1) % 4;
        }
        else
        {
            for (int step = 0; step < command; ++step)
            {
                int next_x = current_x + directions[current_dir].first;
                int next_y = current_y + directions[current_dir].second;
                if (is_obstacles(next_x, next_y, obstacles_set))
                {
                    break;
                }
                current_x = next_x;
                current_y = next_y;
                max_distance = max(max_distance, current_x * current_x + current_y * current_y);
            }
        }
    }
    return max_distance;
}

int main()
{
    return 0;
}