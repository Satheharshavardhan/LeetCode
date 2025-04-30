#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> result;
    unordered_map<int, int> m1;
    for (const auto &num : arr1)
    {
        m1[num] += 1;
    }
    result.push_back(arr2[0]);
    m1[arr2[0]] -= 1;
    for (int i = 0; i < arr2.size(); i += 1)
    {
        if (m1.find(arr2[i]) != m1.end())
        {
            while (m1[arr2[i]] != 0)
            {
                result.push_back(arr2[i]);
                m1[arr2[i]] -= 1;
            }
            m1.erase(arr2[i]);
        }
    }
    vector<int> remaining;
    for (const auto &pair : m1)
    {
        while (pair.second > 0)
        {
            remaining.push_back(pair.first);
            --m1[pair.first];
        }
    }
    sort(remaining.begin(), remaining.end());
    result.insert(result.end(), remaining.begin(), remaining.end());
    return result;
}

int main()
{
    cout << "This is the Solution of the Leetcode problem 1122 i.e. Relative Sort\n";
    string input;
    cout << "Enter the values of arr1 seperated by commas : ";
    getline(cin, input);
    string token;
    vector<int> arr1;
    stringstream ss(input);
    while (getline(ss, token, ','))
    {
        arr1.push_back(stoi(token));
    }
    cout << "Enter the values of arr2 seperated by commas : ";
    getline(cin, input);
    vector<int> arr2;
    stringstream ss1(input);
    while (getline(ss1, token, ','))
    {
        arr2.push_back(stoi(token));
    }
    vector<int> result = relativeSortArray(arr1, arr2);
    for (auto &num : result)
    {
        cout << num << " ";
    }
    return 0;
}