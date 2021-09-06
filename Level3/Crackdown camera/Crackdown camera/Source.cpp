#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) 
{
    int answer = 0;
    vector<pair<int, int>> v;

    for (int i = 0; i < routes.size(); i++)
    {
        int start = routes[i][0];
        int end = routes[i][1];

        v.push_back({ start, end });
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        else
            return a.second < b.second;
    });

    pair<int, int> temp = v[0];
    answer = 1;

    for (int i = 1; i < v.size(); i++)
    {
        if (temp.second < v[i].first)
        {
            answer++;
            temp = v[i];
        }

        if (temp.second >= v[i].second)
            temp = v[i];
    }

    return answer;
}

int main()
{
    vector<vector<int>> routes = {
        {-20, 15},
        {-14, -5},
        {-18, -13},
        {-5, -3}
    };

    cout << solution(routes) << "\n";

    return 0;
}