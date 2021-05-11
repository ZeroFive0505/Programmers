#include <iostream>
#include <list>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    queue<pair<int, int>> q;
    list<pair<int, int>> trucks;
    for (auto i : truck_weights)
        q.push({ i, 0 });
    int t = 0;
    while (1)
    {
        if (!q.empty() && weight - q.front().first>= 0)
        {
            pair<int, int> front = q.front();
            weight -= front.first;
            trucks.push_back(front);
            q.pop();
        }

        if (!trucks.empty() && trucks.front().second >= bridge_length)
        {
            weight += trucks.front().first;
            trucks.pop_front();
            if (!q.empty() && weight - q.front().first >= 0)
            {
                pair<int, int> front = q.front();
                weight -= front.first;
                trucks.push_back(front);
                q.pop();
            }
        }

        for (auto& kv : trucks)
            kv.second++;


        t++;

        if (q.empty() && trucks.empty())
            break;
    }

    answer = t;

    return answer;
}

int main()
{
    int bridge_length = 5;
    int weight = 5;
    vector<int> t = { 2, 2, 2, 2, 1, 1, 1, 1, 1 };

    cout << solution(bridge_length, weight, t);

    return 0;
}