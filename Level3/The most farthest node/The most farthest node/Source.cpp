#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;

int Dijkstra(const int n, int start, vector<vector<int>>& graph)
{
    vector<int> dists(n + 1, INF);
    dists[start] = 0;

    priority_queue<pair<int, int>> pq;

    pq.push({ 0, start });

    while (!pq.empty())
    {
        pair<int, int> current = pq.top();
        pq.pop();

        int u = current.second;
        int currentDist = -current.first;

        for (int v = 0; v < graph[u].size(); v++)
        {
            if (dists[graph[u][v]] > dists[u] + 1)
            {
                dists[graph[u][v]] = dists[u] + 1;
                pq.push({ -dists[graph[u][v]], graph[u][v] });
            }
        }
    }

    int maxDist = *max_element(dists.begin() + 1, dists.end());


    int cnt = 0;
    for (int i = 1; i < dists.size(); i++)
    {
        if (maxDist == dists[i])
            cnt++;
    }


    return cnt;
}

int solution(int n, vector<vector<int>> edge) 
{
    int answer = 0;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < edge.size(); i++)
    {
        int u, v;
        u = edge[i][0];
        v = edge[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    answer = Dijkstra(n, 1, graph);

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