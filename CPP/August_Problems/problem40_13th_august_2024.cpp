#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_list(vector<int> &candidates, int target, int start, vector<vector<int>> &result, vector<int> &current)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size(); ++i)
    {
        if (i > start && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        current.push_back(candidates[i]);
        find_list(candidates, target - candidates[i], i + 1, result, current);
        current.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current_val;
    find_list(candidates, target, 0, result, current_val);
    return result;
}

int main()
{
    return 0;
}