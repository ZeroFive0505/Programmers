#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> jobs) 
{
    int answer = 0;

    sort(jobs.begin(), jobs.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int i = 0;
    int time = 0;

    while (i < jobs.size() || !pq.empty())
    {
        if (i < jobs.size() && time >= jobs[i][0])
        {
            pq.push({ jobs[i][1], jobs[i][0] });
            i++;
            continue;
        }

        if (!pq.empty())
        {
            time += pq.top().first;
            answer += time - pq.top().second;
            pq.pop();
        }
        else
            time = jobs[i][0];
    }

    return answer / jobs.size();
}

int main()
{
    vector<vector<int>> jobs = {
        {0, 3},
        {1, 9},
        {2, 6}
    };

    cout << solution(jobs) << "\n";

    return 0;
}