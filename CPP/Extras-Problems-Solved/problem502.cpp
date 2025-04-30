#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

// int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_capital;
//     priority_queue<int> max_profits;
//     for (int i = 0; i < profits.size(); i++)
//     {
//         min_capital.push({capital[i], profits[i]});
//     }
//     for (int i = 0; i < k; i++)
//     {
//         while (!min_capital.empty() && min_capital.top().first <= w)
//         {
//             max_profits.push(min_capital.top().second);
//             min_capital.pop();
//         }
//         if (max_profits.empty())
//         {
//             break;
//         }
//         w += max_profits.top();
//         max_profits.pop();
//     }
//     return w;
// }

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int n = profits.size();
    vector<int> used(n, 0);
    int result = w;
    while (k > 0)
    {
        vector<int> cap_index;
        for (int i = 0; i < n; i++)
        {
            if (!used[i] && capital[i] <= result)
            {
                cap_index.push_back(i);
            }
        }
        if (cap_index.empty())
        {
            return result;
        }
        int max_profit = 0;
        int max_index = -1;
        for (int i : cap_index)
        {
            if (profits[i] > max_profit)
            {
                max_profit = profits[i];
                max_index = i;
            }
        }
        if (max_index == -1)
        {
            break;
        }
        result += max_profit;
        used[max_index] = 1;
        k--;
    }
    return result;
}

int main()
{
    cout << "This is the solution of the Leetcode problem 502 i.e. IPO\n";
    string input;
    cout << "Enter the profit value seperated by commas : ";
    getline(cin, input);
    stringstream ss(input);
    string token;
    vector<int> profits;
    while (getline(ss, token, ','))
    {
        profits.push_back(stoi(token));
    }
    cout << "Enter the value of Capital seperated by commas : ";
    getline(cin, input);
    stringstream ss1(input);
    vector<int> capital;
    while (getline(ss1, token, ','))
    {
        capital.push_back(stoi(token));
    }
    int k, w;
    cout << "Enter the value of k : ";
    cin >> k;
    cout << "Enter the value of w : ";
    cin >> w;
    int result = findMaximizedCapital(k, w, profits, capital);
    cout << "The maximum capital is : " << result << endl;
    return 0;
}