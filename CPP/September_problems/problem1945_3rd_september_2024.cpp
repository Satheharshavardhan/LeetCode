#include <iostream>
#include <unordered_map>

using namespace std;

// Function to perform the transformation and return the result after k iterations
int getLucky(string s, int k)
{
    unordered_map<char, int> alphabets; // Create a hashmap to store the mapping of characters to their corresponding numeric values
    for (char c = 'a'; c <= 'z'; ++c)   // Loop through the alphabet
    {
        alphabets[c] = c - 'a' + 1; // Map each character to its position in the alphabet (e.g., 'a' -> 1, 'b' -> 2, ..., 'z' -> 26)
    }

    string s_int = ""; // Initialize an empty string to store the numeric representation of the input string

    for (char c : s) // Loop through each character in the input string
    {
        s_int += to_string(alphabets[c]); // Convert the character to its numeric value and append it to s_int
    }

    int result = 0; // Initialize the result variable

    while (k > 0) // Perform the transformation k times
    {
        int num = 0; // Initialize a temporary variable to store the sum of digits

        for (char c : s_int) // Loop through each character (digit) in the string representation of the number
        {
            num += (c - '0'); // Convert the character to its integer value and add it to num
        }

        result = num;           // Store the sum in the result variable
        s_int = to_string(num); // Convert the sum back to a string for the next iteration
        k -= 1;                 // Decrement the counter k
    }

    return result; // Return the final result after k transformations
}

int main()
{
    string s;                      // Declare a string to store the input
    cout << "Enter the String : "; // Prompt the user for input
    cin >> s;                      // Read the input string from the user

    int k;                             // Declare an integer to store the value of k
    cout << "Enter the value of k : "; // Prompt the user for the value of k
    cin >> k;                          // Read the value of k from the user

    int result = getLucky(s, k); // Call the getLucky function with the input string and value of k

    // Output the final result after k transformations
    cout << "The result after the " << k << " transformation to string " << s << " is " << result << endl;

    return 0; // Return 0 to indicate successful execution
}
