#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
{
    vector<int> new_position = positions;
    sort(new_position.begin(), new_position.end());
    stack<int> S;
    for (int i = 0; i < new_position.size(); i += 1)
    {
        if (directions[i] == 'R')
        {
            S.push(i);
        }
        else
        {
            while (!S.empty() and healths[S.top()] < healths[i])
            {
                healths[i] -= 1;
                healths[S.top()] = 0;
            }
            if (!S.empty())
            {
                if (healths[S.top()] == healths[i])
                {
                    healths[S.top()] = 0;
                    S.pop();
                }
                else
                {
                    healths[S.top()] -= 1;
                }
                healths[i] = 0;
            }
        }
    }
    new_position.clear();
    for (const auto &num : healths)
    {
        if (num != 0)
        {
            new_position.push_back(num);
        }
    }
    return new_position;
}

int main()
{
    return 0;
}