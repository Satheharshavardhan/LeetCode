#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Function to check if two strings are almost equal.
 * Two strings are considered almost equal if they are either identical 
 * or can be made identical by swapping exactly two different characters.
 *
 * @param s1 First input string
 * @param s2 Second input string
 * @return true if the strings are almost equal, otherwise false
 */
bool areAlmostEqual(string s1, string s2)
{
    // If both strings are already equal, return true
    if (s1 == s2)
    {
        return true;
    }

    unordered_map<char, int> m1; // Frequency map for s1
    unordered_map<char, int> m2; // Frequency map for s2
    int n = s1.size(); // Length of the strings (assuming both are of equal length)

    // Count the frequency of each character in both strings
    for (int i = 0; i < n; i++)
    {
        m1[s1[i]] += 1;
        m2[s2[i]] += 1;
    }

    // If character frequencies are different, swapping will never make them equal
    if (m1 != m2)
    {
        return false;
    }

    int diff_pos = 0; // Counter to track differing positions

    // Count positions where characters differ
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            diff_pos += 1;
        }
    }

    // If exactly two positions differ, the strings can be made equal with one swap
    if (diff_pos == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Main Code
    return 0;
}
