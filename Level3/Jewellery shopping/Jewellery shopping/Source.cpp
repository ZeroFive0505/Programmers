#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int> answer(2);
    unordered_map<string, int> hashMap;
    set<string> s(gems.begin(), gems.end());

    int start = 0;
    int end = 0;

    for (int i = 0; i < gems.size(); i++)
    {
        string key = gems[i];
        hashMap[key]++;

        if (hashMap.size() == s.size())
            break;
        end++;
    }

    int MIN = end - start;

    answer[0] = start + 1;
    answer[1] = end + 1;

    while (end < gems.size())
    {
        string key = gems[start];
        start++;
        hashMap[key]--;

        if (hashMap[key] == 0)
        {
            end++;
            for (; end < gems.size(); end++)
            {
                hashMap[gems[end]]++;

                if (hashMap[key] != 0)
                    break;
            }

            if (end == gems.size())
                break;
        }

        if (MIN > end - start)
        {
            MIN = end - start;
            answer[0] = start + 1;
            answer[1] = end + 1;
        }
    }

    return answer;
}

int main()
{
    vector<string> gems = {
      "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"
    };

    vector<int> ans = solution(gems);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}