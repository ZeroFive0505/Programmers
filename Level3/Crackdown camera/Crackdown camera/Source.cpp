#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) 
{
    int answer = 1;
    vector<pair<int, int>> v;

    for (int i = 0; i < routes.size(); i++)
        v.push_back({ routes[i][0], routes[i][1] });
    
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second)
            return a.first < b.first;
        else
            a.second < b.second;
    });

    pair<int, int> p = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first > p.second)
        {
            p = v[i];
            answer++;
        }

        if (v[i].second <= p.second)
            p = v[i];
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