#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 101;

int parents[SIZE];

int numSize[SIZE];

struct sNode
{
    int u;
    int v;
    int weight;
};

struct sNodeCmp
{
    bool operator()(const sNode& a, const sNode& b)
    {
        return a.weight > b.weight;
    }
};

int GetParent(int v)
{
    int i = v;
    for (; parents[i] != -1; i = parents[i]);
    return i;
}

void SetUnion(int u, int v)
{
    if (numSize[u] < numSize[v])
    {
        parents[u] = v;
        numSize[v] += numSize[u];
    }
    else
    {
        parents[v] = u;
        numSize[u] += numSize[v];
    }
}

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;

    memset(parents, -1, sizeof(parents));
    fill(numSize, numSize + SIZE, 1);
    priority_queue<sNode, vector<sNode>, sNodeCmp> pq;

    for (int i = 0; i < costs.size(); i++)
    {
        int u = costs[i][0];
        int v = costs[i][1];
        int weight = costs[i][2];

        pq.push({ u, v, weight });
    }

    int nEdge = 0;

    while (nEdge < n - 1)
    {
        sNode top = pq.top();
        pq.pop();

        int u = top.u;
        int v = top.v;
        int w = top.weight;

        int uParent = GetParent(u);
        int vParent = GetParent(v);

        if (uParent != vParent)
        {
            SetUnion(uParent, vParent);
            answer += w;
            nEdge++;
        }
    }

    return answer;
}

int main()
{
    int n = 4;

    vector<vector<int>> costs = {
        {0, 1, 1},
        {0, 2, 2},
        {1, 2, 5},
        {1, 3, 1},
        {2, 3, 8}
    };

    cout << solution(n, costs) << "\n";

    return 0;
}