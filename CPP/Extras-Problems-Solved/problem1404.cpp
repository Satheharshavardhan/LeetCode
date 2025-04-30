#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int convert(string &s)
{
    int result = 0;
    int power = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == '1')
        {
            result += static_cast<int>(pow(2, power));
        }
        ++power;
    }
    return result;
}

int numSteps(string s)
{
    int num = convert(s);
    int steps = 0;
    while (num != 1)
    {
        if (num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            num += 1;
        }
        steps += 1;
    }
    return steps;
}

int main()
{
    cout << "This is the solution of the LeetCode problem 1404 i.e. Number of steps to reduce A number in binnary Representation to One\n";
    string s;
    cout << "Enter the string : ";
    cin >> s;
    int result = numSteps(s);
    cout << "The total number of Steps Required are : " << result << endl;
    return 0;
}