#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

char letters[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

string solution(string s, int n) 
{
    string answer = "";

    string::iterator it;

    for (it = s.begin(); it != s.end(); it++)
    {
        char c;
        if (*it == ' ')
            c = ' ';
        else if (isupper(*it))
        {
            int idx = ((*it) - 65 + n) % 26;
            c = toupper(letters[idx]);
        }
        else if (islower(*it))
        {
            int idx = ((*it) - 97 + n) % 26;
            c = letters[idx];
        }
        answer += c;
    }

    return answer;
}

int main()
{
    string s = "AB";
    int n = 3;
       
    cout << solution(s, n) << "\n";
   

    return 0;
}