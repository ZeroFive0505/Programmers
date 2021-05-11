#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) 
{
    string answer = "";
    int len = phone_number.length();

    for (int i = 0; i < len; i++)
    {
        if (len - i > 4)
            phone_number[i] = '*';
    }

    answer = phone_number;
    return answer;
}

int main()
{
    string number;
    while (1)
    {
        cin >> number;
        cout << solution(number) << "\n";
    }

    return 0;
}