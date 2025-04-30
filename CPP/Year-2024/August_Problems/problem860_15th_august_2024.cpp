#include <iostream>
#include <vector>

using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int change_set[3] = {0, 0, 0};
    for (int i = 0; i < bills.size(); i += 1)
    {
        if (bills[i] == 5)
        {
            change_set[0] += 1;
        }
        else if (bills[i] == 10)
        {
            if (change_set[0] > 0)
            {
                change_set[0] -= 1;
                change_set[1] += 1;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (change_set[1] >= 1 and change_set[0] >= 1)
            {
                change_set[0] -= 1;
                change_set[1] -= 1;
                change_set[2] += 1;
            }
            else
            {
                if (change_set[1] == 0)
                {
                    if (change_set[0] >= 3)
                    {
                        change_set[2] += 1;
                        change_set[0] -= 3;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    return 0;
}