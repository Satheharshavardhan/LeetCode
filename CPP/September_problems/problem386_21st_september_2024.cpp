#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void generate_lexo_smaller(int n, string s, vector<int> &result)
{
    int num = stoi(s);
    if (num > n)
    {
        return;
    }
    result.push_back(num);
    for (int i = 0; i <= 9; i++)
    {
        string new_s = s + to_string(i);
        if (stoi(new_s) > n)
        {
            return;
        }
        generate_lexo_smaller(n, new_s, result);
    }
}

vector<int> lexicalOrder(int n)
{
    vector<int> result;
    if (n < 10)
    {
        for (int i = 1; i <= n; i++)
        {
            result.push_back(i);
        }
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            string s = to_string(i);
            generate_lexo_smaller(n, s, result);
        }
    }
    return result;
}

int main()
{
    int n = 13;
    // int n = 2;
    vector<int> result = lexicalOrder(n);
    for (const auto &num : result)
    {
        cout << num << " ";
    }
    return 0;
}