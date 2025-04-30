#include <iostream>
#include <vector>

using namespace std;

int chalkReplacer(vector<int> &chalk, int k)
{
    long long total_Chalk_Needed = 0;
    for (int student : chalk)
    {
        total_Chalk_Needed += student;
    }
    int remaining_Chalk = k % total_Chalk_Needed;
    for (int index = 0; index < chalk.size(); index += 1)
    {
        if (remaining_Chalk < chalk[index])
        {
            return index;
        }
        remaining_Chalk -= chalk[index];
    }
    return 0;
}

int main()
{
    return 0;
}