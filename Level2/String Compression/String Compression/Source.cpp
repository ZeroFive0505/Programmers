#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> Convert(string s, int n)
{
    vector<string> v;

    for (int i = 0; i < s.length(); i += n)
    {
        v.push_back(s.substr(i, n));
    }

    return v;
}

int solution(string s) 
{

    int answer = 0;
    vector<string> tokens;
    string before;
    int cnt = 1;

    answer = s.length();

    for (int i = 1; i <= s.length() / 2; i++)
    {
        tokens = Convert(s, i);
        string cmp;
        before = tokens[0];
        cnt = 1;

        for (int j = 1; j < tokens.size(); j++)
        {
            if (tokens[j] == before)
                cnt++;
            else
            {
                if (cnt != 1)
                    cmp += to_string(cnt);
                cmp += before;
                before = tokens[j];
                cnt = 1;
            }
        }

        if (cnt != 1)
            cmp += to_string(cnt);
        cmp += before;
        
        answer = answer < cmp.length() ? answer : cmp.length();
    }

    return answer;
}

int main()
{
    string s = "xababcdcdababcdcd";
    cout << solution(s) << "\n";
    return 0;
}