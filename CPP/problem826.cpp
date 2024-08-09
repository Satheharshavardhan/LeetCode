#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    int result = 0;
    vector<pair<int, int>> combined;
    for (int i = 0; i < difficulty.size(); i += 1)
    {
        combined.push_back(make_pair(difficulty[i], profit[i]));
    }
    sort(combined.begin(), combined.end());
    sort(worker.begin(), worker.end());
    for (int i = 0; i < worker.size(); i += 1)
    {
        int j = 0;
        int max = combined[j].second;
        while (combined[j].first <= worker[i] and j < combined.size())
        {
            if (max < combined[j].second)
            {
                max = combined[j].second;
            }
            j += 1;
        }
        result += max;
    }
    return result;
}

int main()
{
    cout << "This is the Solution of the Leetcode Problem 826 i.e. Most Profit Assigning WOrk\n";
    cout << "Enter the value of difficulty : ";
    string input;
    getline(cin, input);
    stringstream ss1(input);
    string token;
    vector<int> difficulty;
    while (getline(ss1, token, ','))
    {
        difficulty.push_back(stoi(token));
    }
    cout << "Enter the value of profit : ";
    getline(cin, input);
    stringstream ss2(input);
    vector<int> profit;
    while (getline(ss2, token, ','))
    {
        profit.push_back(stoi(token));
    }
    cout << "Enter the value of worker : ";
    getline(cin, input);
    stringstream ss3(input);
    vector<int> worker;
    while (getline(ss3, token, ','))
    {
        worker.push_back(stoi(token));
    }
    int result = maxProfitAssignment(difficulty, profit, worker);
    cout << result;
    return 0;
}