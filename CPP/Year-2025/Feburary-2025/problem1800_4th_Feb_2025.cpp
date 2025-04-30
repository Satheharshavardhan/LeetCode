#include <iostream>
#include <vector>

using namespace std;

/**
 * Function to find the maximum sum of any ascending subarray.
 * 
 * An ascending subarray is a contiguous subarray where each element is 
 * strictly greater than the previous one.
 * 
 * @param nums Reference to a vector of integers
 * @return Maximum sum of any ascending subarray
 */
int maxAscendingSum(vector<int> &nums)
{
    vector<int> sub_array; // Temporary vector to store the ascending subarray
    int n = nums.size();   // Size of the input array
    int sum = 0;           // Variable to store the maximum sum

    // Iterate through the array to find ascending subarrays
    for (int i = 0; i < n; i++)
    {
        sub_array.push_back(nums[i]); // Start a new subarray
        int sub_sum = nums[i];        // Initialize sum with the first element

        // Traverse forward to find the longest ascending subarray
        for (int j = i + 1; j < n; j++)
        {
            int num = sub_array.back(); // Get the last element in the subarray

            if (num < nums[j]) // Check if the next element continues the ascending order
            {
                sub_array.push_back(nums[j]); // Add to the subarray
                sub_sum += nums[j];           // Add to the sum
            }
            else
            {
                break; // Stop if the ascending order is broken
            }
        }

        sum = max(sum, sub_sum); // Update the maximum sum if necessary
        sub_array.clear();       // Clear the subarray for the next iteration
    }

    return sum;
}

int main()
{
    // Main code
    return 0;
}
