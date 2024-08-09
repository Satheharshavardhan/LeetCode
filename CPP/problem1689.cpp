#include <iostream>

using namespace std;

int minPartitions(string n)
{
    int max = 0;
    for (int i = 0; i < n.size(); i += 1)
    {
        int num = n[i] - '0';
        if (num > max)
        {
            max = num;
        }
    }
    return max;
}

int main()
{
    cout << "This is the Solution of the Leetcode Problem 1689 i.e. Partitioning into minimum number of Deci-Binnary numbers\n";
    string n;
    cout << "Enter the string : ";
    cin >> n;
    int result = minPartitions(n);
    cout << "The minimum partitioning required is/are : " << result << endl;
}