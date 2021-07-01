#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& parents, vector<int>& mark, int v)
{
    if (visited[v])
        return;

    if (!visited[parents[v]])
    {
        mark[parents[v]] = v;
        return;
    }

    visited[v] = true;

    DFS(graph, visited, parents, mark, mark[v]);

    for (int i : graph[v])
        DFS(graph, visited, parents, mark, i);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) 
{
    bool answer = true;

    vector<vector<int>> graph(n);
    vector<int> parents(n, 0);
    vector<bool> visited(n, false);

    for (int i = 0; i < order.size(); i++)
    {
        int parent = order[i][0];
        int child = order[i][1];

        parents[child] = parent;
    }

    if (parents[0])
        return false;

    for (int i = 0; i < path.size(); i++)
    {
        int u = path[i][0];
        int v = path[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited[0] = true;
    vector<int> mark(n, 0);
    for (int i : graph[0])
        DFS(graph, visited, parents, mark, i);

    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
            return false;
    }

    return answer;
}

int main()
{
    int n = 9;
    vector<vector<int>> path = {
        {0, 1},
        {0, 3},
        {0, 7},
        {8, 1},
        {3, 6},
        {1, 2},
        {4, 7},
        {7, 5}
    };

    vector<vector<int>> order = {
        {8, 5},
        {6, 7},
        {4, 1}
    };

    cout << solution(n, path, order) << "\n";

    return 0;
}