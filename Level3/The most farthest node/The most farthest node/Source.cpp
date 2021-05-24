#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;

void Dijkstra(vector<vector<int>>& graph, int& answer)
{
    priority_queue<pair<int, int>> pq;

    vector<bool> visited(graph.size(), false);
    vector<int> dist(graph.size(), INF);

    visited[1] = true;
    dist[1] = 0;

    pq.push({ 0, 1 });

    while (!pq.empty())
    {
        pair<int, int> top;

        top = pq.top();
        pq.pop();
        int u = top.second;
        int d = -top.first;

        if (d < dist[u])
            continue;

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            int nd = dist[v];

            if (!visited[v] && d + 1 < nd)
            {
                visited[v] = true;
                dist[v] = d + 1;
                pq.push({ -dist[v], v });
            }
        }
    }

    int M = dist[1];
    for (int i = 1; i < dist.size(); i++)
    {
        if (M < dist[i])
            M = dist[i];
    }

    answer = count(dist.begin() + 1, dist.end(), M);
}

int solution(int n, vector<vector<int>> edge) 
{
    int answer = 0;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < edge.size(); i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    Dijkstra(graph, answer);

    return answer;
}

int main()
{
    int n = 6;
    vector<vector<int>> edge = {
        {3, 6},
        {4, 3},
        {3, 2},
        {1, 3},
        {1, 2},
        {2, 4},
        {5, 2}
    };

    cout << solution(n, edge) << "\n";

    return 0;
}