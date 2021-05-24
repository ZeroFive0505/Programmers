#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int> answer;
    unordered_map<string, int> hash;

    set<string> s(gems.begin(), gems.end());

    int m;
    int start = 0, end = 0;

    for (auto i : gems)
    {
        hash[i]++;
        if (hash.size() == s.size())
            break;
        end++;
    }

    m = end - start;
    answer.push_back(start + 1);
    answer.push_back(end + 1);

    while (end < gems.size())
    {
        string key = gems[start];
        hash[key]--;
        start++;

        if (hash[key] == 0)
        {
            end++;
            for (; end < gems.size(); end++)
            {
                hash[gems[end]]++;
                if (key == gems[end])
                    break;
            }

            if (end == gems.size())
                break;
        }

        if (m > end - start)
        {
            answer[0] = start + 1;
            answer[1] = end + 1;
            m = end - start;
        }
    }

    return answer;
}

int main()
{
    vector<string> gems = {
      "AA", "AB", "AC", "AA", "AC"
    };

    vector<int> ans = solution(gems);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}