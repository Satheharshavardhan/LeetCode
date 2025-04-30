#include <iostream>
#include <vector>
#include <string>

using namespace std;

string decodeCiphertext(string encodedText, int rows)
{
    if (rows == 0)
    {
        return "";
    }
    int columns = encodedText.size() / rows;
    vector<vector<char>> matrix(rows, vector<char>(columns));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = encodedText[i * columns + j];
        }
    }
    string decodedText;
    for (int startCol = 0; startCol < columns; ++startCol)
    {
        int i = 0, j = startCol;
        while (i < rows && j < columns)
        {
            decodedText += matrix[i][j];
            ++i;
            ++j;
        }
    }
    while (!decodedText.empty() && decodedText.back() == ' ')
    {
        decodedText.pop_back();
    }
    return decodedText;
}

int main()
{
    cout << "This is the solution of the Leetcode problem 2075 i.e. Decode the Slanted Cipher Text\n";
    string encodedText;
    cout << "Enter the Encoded text : ";
    cin >> encodedText;
    int rows;
    cout << "Enter total number of Rows : ";
    cin >> rows;
    int rows = 3;
    string result = decodeCiphertext(encodedText, rows);
    cout << "The Encodded text is : " << result << endl;
    return 0;
}