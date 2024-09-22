#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        int current = 1; // Start with the smallest lexicographical number
        k--;             // Decrease k because we count the first number as already the 1st

        while (k > 0)
        {
            int steps = countSteps(n, current, current + 1);

            // If k >= steps, skip this entire subtree
            if (k >= steps)
            {
                current++;  // Move to the next sibling (lexicographically)
                k -= steps; // Decrease k by the number of skipped numbers
            }
            else
            {
                current *= 10; // Move down to the next level (child node)
                k--;           // Count the current number
            }
        }

        return current;
    }

private:
    // Count the steps/nodes between `prefix` and `prefix + 1` (in lexicographical order)
    int countSteps(int n, long prefix, long nextPrefix)
    {
        int steps = 0;
        while (prefix <= n)
        {
            steps += min(n + 1L, nextPrefix) - prefix; // Count the numbers in this range
            prefix *= 10;                              // Move to the next level (expand prefix)
            nextPrefix *= 10;                          // Move to the next sibling level
        }
        return steps;
    }
};

int main()
{
    return 0;
}