#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& graph, vector<long long>& sum, int current, int parrent, long long& answer)
{
    for (int i = 0; i < graph[current].size(); i++)
    {
        if (graph[current][i] != parrent)
            DFS(graph, sum, graph[current][i], current, answer);
    }

    sum[parrent] += sum[current];
    answer += abs(sum[current]);
}

long long solution(vector<int> a, vector<vector<int>> edges) 
{
    long long answer = 0;

    vector<long long> sum(a.size());

    for (int i = 0; i < a.size(); i++)
        sum[i] = a[i];

    vector<vector<int>> graph(a.size());

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(graph, sum, 0, 0, answer);

    if (sum[0] == 0)
        return answer;
    else
        return -1;
}

int main()
{
    vector<int> a = { -5, 0, 2, 1, 2 };
    vector<vector<int>> edges = {
        {0, 1},
        {3, 4},
        {2, 3},
        {0, 3}
    };

    cout << solution(a, edges) << "\n";

    return 0;
}