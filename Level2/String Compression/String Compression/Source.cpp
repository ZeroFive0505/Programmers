#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 987654321;

vector<string> Convert(const string& s, int n)
{
    vector<string> v;

    for (int i = 0; i < s.size(); i += n)
    {
        v.push_back(s.substr(i, n));
    }

    return v;
}

int solution(string s) 
{

    int answer = s.size();

    for (int i = 1; i <= s.size() / 2; i++)
    {
        int cnt = 1;
        vector<string> tokens = Convert(s, i);
        string before = tokens[0];
        string compressed;
        for (int j = 1; j < tokens.size(); j++)
        {
            if (before == tokens[j])
                cnt++;
            else
            {
                if (cnt != 1)
                    compressed += to_string(cnt);
                compressed += before;
                before = tokens[j];
                cnt = 1;
            }
        }

        if (cnt != 1)
            compressed += to_string(cnt);
        compressed += before;

        answer = min(answer, (int)compressed.size());
    }

    return answer;
}

int main()
{
    string s = "abcdabcd";
    cout << solution(s) << "\n";
    return 0;
}