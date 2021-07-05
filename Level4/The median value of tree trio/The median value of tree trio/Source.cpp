#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Graph;
vector<bool> Visited;
int Leaf;
int Max_Len;
int Cnt;

void DFS(int cur, int len, bool terminate)
{
    if (Visited[cur])
        return;

    if (!terminate)
    {
        if (len > Max_Len)
        {
            Leaf = cur;
            Max_Len = len;
        }
    }
    else
    {
        if (len > Max_Len)
        {
            Leaf = cur;
            Cnt = 1;
            Max_Len = len;
        }
        else if (len == Max_Len)
            Cnt++;
    }

    Visited[cur] = true;

    for (int i = 0; i < Graph[cur].size(); i++)
    {
        int next = Graph[cur][i];
        DFS(next, len + 1, terminate);
    }
}

void Search(int start, int n, bool terminate)
{
    Cnt = 0;
    Max_Len = 0;
    Visited.assign(n + 1, false);

    DFS(start, 0, terminate);
}

int solution(int n, vector<vector<int>> edges) 
{
    Graph.resize(n + 1);
    Visited.resize(n + 1, false);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    Search(1, n, false);
    Search(Leaf, n, true);

    if (Cnt >= 2)
        return Max_Len;
    else
    {
        Search(Leaf, n, true);
        if (Cnt >= 2)
            return Max_Len;
        else
            return Max_Len - 1;
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {1, 5},
        {2, 5},
        {3, 5},
        {4, 5}
    };

    cout << solution(n, edges) << "\n";

    return 0;
}