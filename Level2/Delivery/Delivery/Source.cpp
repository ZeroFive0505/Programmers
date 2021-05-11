#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 51;

vector<pair<int, int>> graph[SIZE];
int DIST[SIZE];

void Dijkstra(int start)
{
    DIST[start] = 0;

    priority_queue<pair<int, int>> pq;

    pq.push({ 0, start });

    while (!pq.empty())
    {
        int d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();


        if (d < DIST[u])
            continue;

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;

            if (DIST[u] + graph[u][i].second < DIST[v])
            {
                DIST[v] = DIST[u] + graph[u][i].second;
                pq.push({ -DIST[v], v });
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) 
{
    int answer = 0;

    fill(DIST, DIST + SIZE, INT_MAX);

    for (int i = 0; i < road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int d = road[i][2];

        graph[a].push_back({ b, d });
        graph[b].push_back({ a, d });
    }

    Dijkstra(1);

    for (int i = 1; i <= N; i++)
    {
        if (DIST[i] <= K)
            answer++;
    }

    return answer;
}

int main()
{
    int N = 6;
    int K = 4;
    vector<vector<int>> road = {
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 2},
        {3, 4, 3},
        {3, 5, 2},
        {3, 5, 3},
        {5, 6, 1}
    };

    cout << solution(N, road, K) << "\n";

    return 0;
}