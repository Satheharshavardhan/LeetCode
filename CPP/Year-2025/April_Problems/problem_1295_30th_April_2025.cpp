#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to count the numbers in a vector that have an even number of digits.
int findNumbers(vector<int> &nums)
{
    int count = 0; // Initialize a counter to store the number of even-digit numbers.

    // Iterate through each number in the input vector.
    for (const auto &num : nums)
    {
        string s = to_string(num); // Convert the integer to a string.
        if (s.size() % 2 == 0)     // Check if the length of the string (number of digits) is even.
        {
            count++; // If the number of digits is even, increment the counter.
        }
    }
    return count; // Return the total count of even-digit numbers.
}

int main()
{
    // Example usage of the findNumbers function.
    vector<int> numbers1 = {12, 345, 2, 6, 7896};
    int evenDigitCount1 = findNumbers(numbers1);
    cout << "Number of even-digit numbers in numbers1: " << evenDigitCount1 << endl; // Output: 2

    vector<int> numbers2 = {555, 901, 482, 1771};
    int evenDigitCount2 = findNumbers(numbers2);
    cout << "Number of even-digit numbers in numbers2: " << evenDigitCount2 << endl; // Output: 1

    vector<int> numbers3 = {2, 22, 222, 2222, 22222};
    int evenDigitCount3 = findNumbers(numbers3);
    cout << "Number of even-digit numbers in numbers3: " << evenDigitCount3 << endl; // Output: 2

    return 0; // Indicate successful program execution.
}
