#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int minMovesToSeat(vector<int> &seats, vector<int> &students)
{
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int result = 0;
    for (int i = 0; i < seats.size(); i += 1)
    {
        result += abs(seats[i] - students[i]);
    }
    return result;
}

int main()
{
    cout << "This is the solution of the Leetcode problem 2037 i.e. Minimum number of moves to Seat Everyone\n";
    string input;
    cout << "Enter the values of seat seperated by commas : ";
    getline(cin, input);
    stringstream ss(input);
    string token;
    vector<int> seats;
    while (getline(ss, token, ','))
    {
        seats.push_back(stoi(token));
    }
    cout << "Enter the values of student seperated by commas : ";
    getline(cin, input);
    stringstream ss1(input);
    vector<int> students;
    while (getline(ss1, token, ','))
    {
        students.push_back(stoi(token));
    }
    int result = minMovesToSeat(seats, students);
    cout << "The minimun moves required to seat everyone is/are : " << result << endl;
    return 0;
}