#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
{
    vector<int> ans;
    int n = heights.size();
    int alice_pos, bob_pos;
    for (const auto &query : queries)
    {
        alice_pos = query[0];
        bob_pos = query[1];
        int min_index = max(alice_pos, bob_pos);
        for (int i = min_index; i < n; i++)
        {
            if (heights[i] >= heights[alice_pos] && heights[i] >= heights[bob_pos])
            {
                min_index = i;
                break;
            }
            min_index = -1;
        }
        ans.push_back(min_index);
    }
    return ans;
}

int main()
{
    vector<int> heights = {1, 2, 1, 2, 1, 2};
    vector<vector<int>> queries = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}};
    vector<int> ans = leftmostBuildingQueries(heights, queries);
    for (const auto &num : ans)
    {
        cout << num;
    }
    return 0;
}