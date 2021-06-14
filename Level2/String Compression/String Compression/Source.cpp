#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int INF = 987654321;

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

    int answer = INF;
    vector<string> tokens;
    string before;
    int cnt;

    for (int i = 1; i <= s.size() / 2; i++)
    {
        cnt = 1;
        tokens = Convert(s, i);
        before = *tokens.begin();
        string cmp;

        for (int j = 1; j < tokens.size(); j++)
        {
            if (before == tokens[j])
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

        answer = answer > cmp.size() ? cmp.size() : answer;
    }

    return answer;
}

int main()
{
    string s = "aabbaccc";
    cout << solution(s) << "\n";
    return 0;
}