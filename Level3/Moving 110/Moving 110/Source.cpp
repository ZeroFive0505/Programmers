#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetLastZeroIdx(const string& s)
{
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '0')
            return i;
    }

    return -1;
}

vector<string> solution(vector<string> s) 
{
    vector<string> answer;

    for (int i = 0; i < s.size(); i++)
    {
        string str;
        int cnt = 0;

        for (int j = 0; j < s[i].size(); j++)
        {
            str += s[i][j];

            if (str.size() >= 3)
            {
                if (str.substr(str.size() - 3, 3) == "110")
                {
                    cnt++;
                    str.erase(str.size() - 3, 3);
                }
            }
        }

        int lastIndex = GetLastZeroIdx(str);

        if (lastIndex == -1)
        {
            string result;

            while (cnt--)
                result += "110";

            result += str;

            answer.push_back(result);
        }
        else
        {
            string result;

            for (int j = 0; j < str.size(); j++)
            {
                if (j == lastIndex)
                {
                    result += str[j];
                    while (cnt--)
                        result += "110";
                }
                else
                    result += str[j];
            }

            answer.push_back(result);
        }
    }

    return answer;
}

int main()
{
    vector<string> s = {
        "1110",
        "100111100",
        "0111111010"
    };


    vector<string> ans = solution(s);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}