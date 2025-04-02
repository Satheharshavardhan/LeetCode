#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum triplet value from a given vector of integers.
long long maximumTripletValue(vector<int> &nums)
{
    long long max_value = 0; // Initialize the maximum value to 0.
    int n = nums.size();     // Get the size of the input vector.

    // Iterate through all possible triplets (i, j, k) in the vector.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                // Calculate the triplet value (nums[i] - nums[j]) * nums[k].
                // Cast nums[i], nums[j], and nums[k] to long long to prevent integer overflow during multiplication.
                long long current_value = (long long)(nums[i] - nums[j]) * (long long)nums[k];

                // Update max_value with the larger of its current value and the calculated triplet value.
                max_value = max(max_value, current_value);
            }
        }
    }

    return max_value; // Return the maximum triplet value found.
}

int main()
{
    vector<int> test_nums = {10, 2, 5, 8, 3};
    long long result = maximumTripletValue(test_nums);
    cout << "Maximum Triplet Value: " << result << endl;
    return 0;
}