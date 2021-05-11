#include <iostream>
#include <string>

using namespace std;


string solution(string s) 
{
    string answer = "";
    int len = s.length();
    if (len % 2 == 0)
    {
        int mid = len / 2;
        answer += s.at(mid - 1);
        answer += s.at(mid);
    }
    else
    {
        answer = s.at(len / 2);
    }
    return answer;
}

int main()
{
    string s;
    while (1)
    {
        cin >> s;
        if (s == "")
            break;
        cout << solution(s) << "\n";
    }

	return 0;
}