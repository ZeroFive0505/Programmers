#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    int id = 0;
    map<string, vector<int>> hashGens;
    map<int, int> playTimes;
    map<int, string> topChart;

    for (int i = 0; i < genres.size(); i++)
    {
        string gen = genres[i];
        hashGens[gen].push_back(id);
        playTimes[id] = plays[i];
        id++;
    }

    for (int i = 0; i < genres.size(); i++)
    {
        string gen = genres[i];
        vector<int> v = hashGens[gen];
        int sum = 0;
        for (auto i : v)
            sum += playTimes[i];
        topChart[sum] = gen;
    }

    for (auto i = topChart.rbegin(); i != topChart.rend(); i++)
    {
        string gen = (*i).second;
        
        vector<int> v = hashGens[gen];
        vector<pair<int, int>> temp;

        for (auto i : v)
        {
            int p = playTimes[i];
            temp.push_back({ i, p });
        }

        sort(temp.begin(), temp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        int cnt = 0;

        for (int i = 0; i < temp.size() && cnt != 2; i++, cnt++)
        {
            answer.push_back(temp[i].first);
        }

    }


    return answer;
}

int main()
{
    vector<string> genres = {
        "classic",
        "pop",
        "classic",
        "classic",
        "pop"
    };

    vector<int> plays = {
        500, 600, 150, 800, 2500
    };

    vector<int> ans = solution(genres, plays);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}