#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

bool solution(string s) 
{
    bool answer = true;
    int len = s.length();
    if (len == 4 || len == 6)
    {
        for (int i = 0; i < len; i++)
        {
            if (isalpha(s[i]))
            {
                answer = false;
                break;
            }
        }
    }
    else
        answer = false;

    return answer;
}

int main()
{

	return 0;
}