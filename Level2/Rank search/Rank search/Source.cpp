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
    map<string, vector<int>> info_scores;

    for (int i = 0; i < info.size(); i++)
    {
        stringstream ss(info[i]);

        int score;

        vector<string> v;

        for (int j = 0; j < 4; j++)
        {
            string tmp;
            ss >> tmp;
            v.push_back(tmp);
        }

        ss >> score;

        for (int j = 0; j < 16; j++)
        {
            unsigned int bit = 1;
            string key;
            for (int k = 0; k < 4; k++, bit <<= 1)
            {
                if (j & bit)
                    key += v[k];
                else
                    key += '-';
            }

            info_scores[key].push_back(score);
        }
    }

    for (auto& i : info_scores)
        stable_sort(i.second.begin(), i.second.end());

    for (int i = 0; i < query.size(); i++)
    {
        stringstream ss(query[i]);
        string key;

        int score;

        for (int j = 0; j < 7; j++)
        {
            string tmp;
            ss >> tmp;

            if (tmp != "and")
                key += tmp;
        }

        ss >> score;

        vector<int> scores = info_scores[key];

        int idx = lower_bound(scores.begin(), scores.end(), score) - scores.begin();

        answer.push_back(scores.size() - idx);
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