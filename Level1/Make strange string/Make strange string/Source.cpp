#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

string solution(string s) 
{
    string answer = "";
    int len = s.length();
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (c == ' ')
            cnt = 0;
        
        if (cnt % 2 == 0)
        {
            if (c != ' ')
            {
                c = toupper(s[i]);
                cnt++;
            }
        }
        else
        {
            if (c != ' ')
            {
                c = tolower(s[i]);
                cnt++;
            }
        }

        answer += c;
    }

    return answer;
}

int main()
{
    string s;
    while (1)
    {
        getline(cin, s);
        cout << solution(s) << "\n";
    }

    return 0;
}