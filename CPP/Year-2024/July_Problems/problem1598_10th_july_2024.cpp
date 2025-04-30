#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minOperations(vector<string> &logs)
{
    int current = 1;
    for (const auto &log : logs)
    {
        if (log.find("../") != log.npos and current != 1)
        {
            current -= 1;
        }
        else if (log.find("./") != log.npos)
        {
            current = current;
        }
        else
        {
            current += 1;
        }
    }
    return (current - 1);
}

int main()
{
    vector<string> Logs = {"d1/", "d2/", "../", "d21/", "./"};
    cout << minOperations(Logs);
    return 0;
}