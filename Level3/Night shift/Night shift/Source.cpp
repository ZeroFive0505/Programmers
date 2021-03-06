#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) 
{
    long long answer = 0;

    priority_queue<int> pq(works.begin(), works.end());

    for (int i = 0; i < n; i++)
    {
        if (pq.top() > 0)
        {
            int t = pq.top();
            t--;
            pq.pop();
            pq.push(t);
        }
    }

    while (!pq.empty())
    {
        answer += (long long)pq.top() * (long long)pq.top();
        pq.pop();
    }

    return answer;
}

int main()
{
    int n = 4;
    vector<int> works = { 4, 3, 3 };

    cout << solution(n, works) << "\n";

    return 0;
}