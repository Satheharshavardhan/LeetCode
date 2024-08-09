#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSeniors(vector<string> &details)
{
    int total = 0;
    for (const auto &str : details)
    {
        int age = (str[11] - '0') * 10 + (str[12] - '0');
        if (age > 60)
        {
            total += 1;
        }
    }
    return total;
}

int main()
{
    return 0;
}