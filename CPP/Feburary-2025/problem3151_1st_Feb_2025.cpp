#include <iostream>
#include <vector>

using namespace std;

/**
 * Function to check if two numbers have opposite parity.
 * Parity means whether a number is even or odd.
 * 
 * @param num1 First number
 * @param num2 Second number
 * @return true if one number is even and the other is odd, otherwise false
 */
bool has_same_parity(int num1, int num2)
{
    // Check if one number is even and the other is odd
    if ((num1 % 2 == 0 && num2 % 2 == 1) || (num1 % 2 == 1 && num2 % 2 == 0))
    {
        return true;
    }
    return false;
}

/**
 * Function to determine if an array is "special".
 * An array is considered special if all adjacent elements have opposite parity.
 * 
 * @param nums Reference to a vector of integers
 * @return true if the array is special, otherwise false
 */
bool isArraySpecial(vector<int> &nums)
{
    int n = nums.size();

    // A single element array is always special
    if (n == 1)
        return true;

    // Iterate through the array and check adjacent elements
    for (int i = 0; i < n - 1; i++)
    {
        // If adjacent elements do not have opposite parity, return false
        if (!has_same_parity(nums[i], nums[i + 1]))
        {
            return false;
        }
    }

    // If all adjacent elements have opposite parity, return true
    return true;
}

int main()
{
    // Main code
    return 0;
}
