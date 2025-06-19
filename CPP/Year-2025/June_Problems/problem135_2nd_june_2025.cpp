#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int> &ratings)
{
    int candies = 1;
    int current = 1, previous = 1;
    int n = ratings.size();

    for (int index = 1; index < n; index++)
    {
        if (ratings[index] > ratings[index - 1])
        {
            current++;
        }
        else
        {
            previous = current;
            candies += current;
        }
    }
    return candies;
}

int main()
{
    return 0;
}