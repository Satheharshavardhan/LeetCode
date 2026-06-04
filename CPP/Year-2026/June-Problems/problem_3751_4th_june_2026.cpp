#include <iostream>
#include <string>

using namespace std;

int totalWaviness(int num1, int num2)
{
    int total_waviness = 0;
    for (int i = num1; i <= num2; i++)
    {
        string num_str = to_string(i);
        if (num_str.length() >= 3)
        {
            for (char j = 1; j <= num_str.length() - 2; j++)
            {
                if ((num_str[j] - '0') > (num_str[j - 1] - '0') and (num_str[j] - '0') > (num_str[j + 1] - '0'))
                {
                    total_waviness += 1;
                }
                if ((num_str[j] - '0') < (num_str[j - 1] - '0') and (num_str[j] - '0') < (num_str[j + 1] - '0'))
                {
                    total_waviness += 1;
                }
            }
        }
    }
    return total_waviness;
}

int main()
{
    cout << totalWaviness(120, 130) << endl;
    return 0;
}