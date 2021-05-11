#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) 
{
    string answer = "";
    stringstream ss(s);
    int m;
    int M;

    ss >> m;

    M = m;

    while (ss.good())
    {
        int temp;

        ss >> temp;

        if (m > temp)
            m = temp;
        
        if (M < temp)
            M = temp;
    }

    answer += to_string(m);
    answer += " ";
    answer += to_string(M);

    return answer;
}


int main()
{
    string s = "-1 -1";
    cout << solution(s) << "\n";
    return 0;
}