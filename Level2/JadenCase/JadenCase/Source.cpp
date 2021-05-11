#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>

using namespace std;

string solution(string s) 
{
    string answer = "";

    size_t pos;

    while ((pos = s.find(" ")) != string::npos)
    {
        string token = s.substr(0, pos);
        transform(token.begin(), token.end(), token.begin(), ::tolower);

        if (isalpha(token[0]))
            token[0] = toupper(token[0]);
        answer += token + " ";
        s.erase(0, pos + 1);
    }

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    if(islower(s[0]))
        s[0] = toupper(s[0]);

    answer += s;

    return answer;
}


int main()
{
    string s = "for the last week";
    
    cout << solution(s) << "\n";
    return 0;
}