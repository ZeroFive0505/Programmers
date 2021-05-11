#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    int deg = 1;
    string::reverse_iterator it;
    for (it = s.rbegin(); it != s.rend(); it++)
    {
        if (isdigit(*it))
        {
            answer += ((*it) - '0') * deg;
            deg *= 10;
        }
        else if (*it == '-')
            answer *= -1;
    }
    return answer;
}

int main()
{
    string s;
    while (1)
    {
        cin >> s;
        cout << solution(s) << "\n";
    }
	return 0;
}