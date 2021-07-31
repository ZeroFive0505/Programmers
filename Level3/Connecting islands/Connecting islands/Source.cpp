#include <iostream>
#include <cstring>
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
    int w;

    bool operator<(const sNode& rhs) const
    {
        return this->w < rhs.w;
    }

    bool operator>(const sNode& rhs) const
    {
        return this->w > rhs.w;
    }
};

int GetParent(int v)
{
    int i;
    for (i = v; parents[i] != -1; i = parents[i]);
    return i;
}

void SetUnion(int u, int v)
{
    if (numSize[u] < numSize[v])
    {
        numSize[v] += numSize[u];
        parents[u] = v;
    }
    else
    {
        numSize[u] += numSize[v];
        parents[v] = u;
    }
}

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
    priority_queue<sNode, vector<sNode>, greater<sNode>> pq;
    memset(parents, -1, sizeof(parents));

    for (int i = 0; i < costs.size(); i++)
    {
        int u = costs[i][0];
        int v = costs[i][1];
        int w = costs[i][2];

        pq.push({ u, v, w });
    }

    int nEdge = 0;

    while (nEdge < n - 1)
    {
        sNode current = pq.top();
        pq.pop();

        int uParent = GetParent(current.u);
        int vParent = GetParent(current.v);

        if (uParent != vParent)
        {
            SetUnion(uParent, vParent);
            answer += current.w;
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