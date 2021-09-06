#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;


vector<int> solution(vector<string> info, vector<string> query) 
{
    vector<int> answer;
    map<string, vector<int>> hashMap;

    for (int i = 0; i < info.size(); i++)
    {
        stringstream ss(info[i]);
        vector<string> v;
        for (int j = 0; j < 4; j++)
        {
            string temp;
            ss >> temp;
            v.push_back(temp);
        }

        int score;

        ss >> score;

        for (int j = 0; j < 16; j++)
        {
            unsigned int mask = 1;
            string key;
            for (int k = 0; k < 4; k++, mask <<= 1)
            {
                if (j & mask)
                    key += v[k];
                else
                    key += "-";
            }

            hashMap[key].push_back(score);
        }
    }

    for (auto& kv : hashMap)
    {
        sort(kv.second.begin(), kv.second.end());
    }

    for (int i = 0; i < query.size(); i++)
    {
        stringstream ss(query[i]);
        string key;
        for (int j = 0; j < 7; j++)
        {
            string temp;

            ss >> temp;

            if (temp != "and")
                key += temp;
        }

        int score;

        ss >> score;

        int idx = lower_bound(hashMap[key].begin(), hashMap[key].end(), score) - hashMap[key].begin();

        answer.push_back(hashMap[key].size() - idx);
    }

    return answer;
}

int main()
{
    vector<string> info = { "java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50" };

    vector<string> query = { "java and backend and junior and pizza 100",
        "python and frontend and senior and chicken 200",
        "cpp and - and senior and pizza 250", "- and backend and senior and - 150",
        "- and - and - and chicken 100",
        "- and - and - and - 150" };

    vector<int> ans = solution(info, query);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}