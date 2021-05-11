#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    vector<pair<double, int>> rate;
    map<int, int> m;
    int size = stages.size();

    for (auto i : stages)
        m[i]++;
    int last = 0;
    for (int i = 1; i < N + 1; i++)
    {
        if (m.count(i))
        {
            int player = size - last;
            size -= last;
            rate.push_back({ (double)m[i] / player, i });
            last = m[i];
        }
        else
            rate.push_back({ 0.0f, i });
    }


    sort(rate.begin(), rate.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        else
            return a.first > b.first;
    });


    for (const auto& kv : rate)
        answer.push_back(kv.second);

    return answer;
}

int main()
{
    int N = 8;
    vector<int> stages = { 1,2,3,4,5,6,7 };
    vector<int> s = solution(N, stages);
    for (auto i : s)
        cout << i << " ";
    cout << "\n";
    return 0;
}