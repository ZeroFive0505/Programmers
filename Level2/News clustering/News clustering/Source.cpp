#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM = 65536;

int solution(string str1, string str2) 
{
    int answer = 0;
    int nIntersection = 0;
    int nUnion = 0;

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    vector<string> set1, set2;

    for (int i = 0; i < str1.size() - 1; i++)
    {
        string sub = str1.substr(i, 2);
        if (isalpha(sub[0]) && isalpha(sub[1]))
            set1.push_back(sub);
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        string sub = str2.substr(i, 2);
        if (isalpha(sub[0]) && isalpha(sub[1]))
            set2.push_back(sub);
    }

    if (set1.empty() && set2.empty())
        return NUM;

    nUnion = set1.size() + set2.size();

    if (set1.size() > set2.size())
    {
        for (int i = 0; i < set2.size(); i++)
        {
            auto iter = find(set1.begin(), set1.end(), set2[i]);

            if (iter != set1.end())
            {
                set1.erase(iter);
                nIntersection++;
            }
        }
    }
    else
    {
        for (int i = 0; i < set1.size(); i++)
        {
            auto iter = find(set2.begin(), set2.end(), set1[i]);

            if (iter != set2.end())
            {
                set2.erase(iter);
                nIntersection++;
            }
        }
    }

    nUnion -= nIntersection;

    if (nUnion == 0)
        return NUM;

    answer = (double)nIntersection / nUnion * NUM;

    return answer;
}

int main()
{
    string str1 = "aa1+aa2";
    string str2 = "AAAA12";

    cout << solution(str1, str2) << "\n";

    return 0;
}