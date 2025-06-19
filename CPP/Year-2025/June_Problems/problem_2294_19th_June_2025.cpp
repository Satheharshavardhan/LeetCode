#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to partition the array into the minimum number of subsequences
// such that the difference between the max and min in each subsequence is <= k
int partitionArray(vector<int> &nums, int k)
{
    // Step 1: Sort the array to process elements in increasing order
    sort(nums.begin(), nums.end());

    // At least one subsequence will always be there
    int total_subsequences = 1;

    // Track the minimum value of the current subsequence
    int minimum = nums[0];

    int n = nums.size();

    // Step 2: Traverse through the sorted array
    for (int index = 1; index < n; index++)
    {
        // If the current element cannot be added to the existing subsequence
        // because its difference from the current minimum exceeds k
        if ((nums[index] - minimum) > k)
        {
            // Start a new subsequence
            total_subsequences++;

            // Reset the minimum for the new subsequence
            minimum = nums[index];
        }
    }

    // Return the total number of valid subsequences formed
    return total_subsequences;
}

int main()
{
    // Example input
    vector<int> nums = {3, 6, 1, 2, 5};
    int k = 2;

    // Output the result
    cout << partitionArray(nums, k);

    return 0;
}
