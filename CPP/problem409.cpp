#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int longestPalindrome(string s)
{
    int result = 0;
    unordered_set<char> set;
    for (char c : s)
    {
        if (set.find(c) != set.end())
        {
            result += 2;
            set.erase(c);
        }
        else
        {
            set.insert(c);
        }
    }
    if (set.empty())
    {
        return result;
    }
    else
    {
        return result + 1;
    }
}

int main()
{
    cout << "This is the solution of the Leetcode problem 409 i.e. Longest Palindrome\n";
    string s;
    cout << "Enter the String : ";
    cin >> s;
    int result = longestPalindrome(s);
    cout << "The length of the Longest Palindrome is : " << result << endl;
    return 0;
}