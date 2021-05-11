#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM = 65536;

int solution(string str1, string str2) 
{
    int answer = 0;
    int intersection = 0;
    int uni = 0;

    vector<string> s1, s2, words;

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    for (int i = 0; i < str1.size() - 1; i++)
    {
        string sub = str1.substr(i, 2);
        if (isalpha(sub[0]) && isalpha(sub[1]))
            s1.push_back(sub);
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        string sub = str2.substr(i, 2);
        if (isalpha(sub[0]) && isalpha(sub[1]))
            s2.push_back(sub);
    }

    if (s1.empty() && s2.empty())
        return NUM;

    uni = s1.size() + s2.size();

    if (s1.size() > s2.size())
    {
        for (int i = 0; i < s2.size(); i++)
        {
            auto itr = find(s1.begin(), s1.end(), s2[i]);
            if (itr != s1.end())
            {
                intersection++;
                s1.erase(itr);
            }
        }
    }
    else
    {
        for (int i = 0; i < s1.size(); i++)
        {
            auto itr = find(s2.begin(), s2.end(), s1[i]);
            if (itr != s2.end())
            {
                intersection++;
                s2.erase(itr);
            }
        }
    }

    uni -= intersection;

    if (uni == 0)
        return NUM;
    
    answer = (double)intersection / uni * NUM;

    return answer;
}

int main()
{
    string str1 = "aa1+aa2";
    string str2 = "AAAA12";

    cout << solution(str1, str2) << "\n";

    return 0;
}