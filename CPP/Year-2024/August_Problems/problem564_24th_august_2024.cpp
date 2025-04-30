#include <iostream>

using namespace std;

bool is_palindrome(string n)
{
    for (int i = 0; i < (int)(n.size() / 2); i += 1)
    {
        if (n[i] != n[n.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

string nearestPalindromic(string n)
{
    if (is_palindrome(n))
    {
        if (n.size() == 1)
        {
            n = stoi(n) - 1;
            return n;
        }
    }
}

int main()
{
    cout << nearestPalindromic("1");
    return 0;
}