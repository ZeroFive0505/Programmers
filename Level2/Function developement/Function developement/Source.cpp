#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    queue<pair<int, int>> q;
    int size = progresses.size();
    int day = 1;
    for (int i = 0; i < size; i++)
        q.push({ progresses[i], speeds[i] });

    while (!q.empty())
    {
        int cnt = 0;

        while (!q.empty() && q.front().first + q.front().second * day >= 100)
        {
            q.pop();
            cnt++;
        }

        if (cnt != 0)
            answer.push_back(cnt);

        day++;
    }

    return answer;
}

int main()
{
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };
    
    vector<int> ans = solution(progresses, speeds);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}