#include <iostream>
#include <vector>

using namespace std;

/**
 * Function to find the length of the longest monotonic subarray.
 * A monotonic subarray is either strictly increasing or strictly decreasing.
 * 
 * @param nums Reference to a vector of integers
 * @return Length of the longest strictly increasing or decreasing subarray
 */
int longestMonotonicSubarray(vector<int> &nums)
{
    int n = nums.size();

    // If the array has only one element, the longest monotonic subarray is of length 1.
    if (n == 1)
        return 1;

    int inc_len = 1, dec_len = 1; // Track lengths of increasing and decreasing sequences
    int max_length = 1; // Stores the maximum length found

    // Traverse the array from the second element
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1]) // Strictly increasing sequence
        {
            inc_len++; // Increase increasing sequence length
            dec_len = 1; // Reset decreasing sequence length
        }
        else if (nums[i] < nums[i - 1]) // Strictly decreasing sequence
        {
            dec_len++; // Increase decreasing sequence length
            inc_len = 1; // Reset increasing sequence length
        }
        else // If the current element is equal to the previous one, reset both counts
        {
            inc_len = 1;
            dec_len = 1;
        }

        // Update the maximum length found so far
        max_length = max(max_length, max(inc_len, dec_len));
    }

    return max_length;
}

int main()
{
    // Main Code
    return 0;
}
