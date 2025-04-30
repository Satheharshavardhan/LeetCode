#include <iostream>
#include <bitset>
#include <string>

using namespace std;

string removeLeadingZeros(const string &binary_num)
{
    size_t non_zero_pos = binary_num.find_first_not_of('0');
    if (non_zero_pos != string::npos)
    {
        return binary_num.substr(non_zero_pos);
    }
    return "0";
}

int findComplement(int num)
{
    bitset<32> binary_num(num);
    string bin_num = removeLeadingZeros(binary_num.to_string());
    for (int i = 0; i < bin_num.size(); i += 1)
    {
        if (bin_num[i] == '1')
        {
            bin_num[i] = '0';
        }
        else
        {
            bin_num[i] = '1';
        }
    }
    num = stoi(bin_num, nullptr, 2);
    return num;
}

int main()
{
    cout << findComplement(1);
    return 0;
}

// The Best solution for this problem.
/*
class Solution
{
public:
    int findComplement(int num)
    {
        int max = INT_MAX;
        return num ^ (INT_MAX >> ((int)log2(INT_MAX) - (int)log2(num)));
    }
};
*/