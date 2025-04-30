#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int calculate_XOR_a(vector<int> &arr, int i, int j)
{
    int ans = arr[i];
    for (int x = i + 1; x < j; x += 1)
    {
        ans ^= arr[x];
    }
    return ans;
}

int calculate_XOR_b(vector<int> &arr, int j, int k)
{
    int ans = arr[j];
    for (int x = j + 1; x <= k; x += 1)
    {
        ans ^= arr[x];
    }
    return ans;
}

int countTriplets(vector<int> &arr)
{
    int i = 0, count = 0;
    int n = arr.size();
    while (i < n)
    {
        int j = i + 1;
        while (j < n)
        {
            int k = j + 1;
            while (k < n)
            {
                int a = calculate_XOR_a(arr, i, j);
                int b = calculate_XOR_b(arr, j, k);
                if (a == b)
                {
                    count += 1;
                }
                k += 1;
            }
            j += 1;
        }
        i += 1;
    }
    return count;
}

int main()
{
    cout << "This is the solution of the Leetcode problem 1552 i.e. Count triplets that can form two arrays of Equal XOR\n";
    string input;
    cout << "Enter the values seperated by commas : ";
    getline(cin, input);
    stringstream ss(input);
    string token;
    vector<int> arr;
    while (getline(ss, token, ','))
    {
        arr.push_back(stoi(token));
    }
    int result = countTriplets(arr);
    cout << "The total number of triplets are : " << result << endl;
    return 0;
}