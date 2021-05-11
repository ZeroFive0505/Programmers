#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(string s) 
{
    string answer = "";
    sort(s.begin(), s.end(), [](const char& a, const char& b) {return a > b; });
    answer = s;
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