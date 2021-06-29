#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) 
{
    int answer = 0;
    long long sum = 0;
    long long before = 0;

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < food_times.size(); i++)
    {
        sum += food_times[i];
        pq.push({ -food_times[i], (i + 1) });
    }

    if (sum <= k)
        return -1;

    while ((-pq.top().first - before) * pq.size() <= k)
    {
        k -= (-pq.top().first - before) * pq.size();
        before = -pq.top().first;
        pq.pop();
    }

    vector<pair<int, int>> v;
    
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    answer = v[k % v.size()].second;

    return answer;
}

int main()
{
    vector<int> food_times = { 3, 1, 2 };
    long long k = 5;

    cout << solution(food_times, k) << "\n";

    return 0;
}