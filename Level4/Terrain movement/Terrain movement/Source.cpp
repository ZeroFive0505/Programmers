#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 301;
int visited[SIZE][SIZE];
int parent[SIZE * SIZE];
int numSize[SIZE * SIZE];
struct sDelta
{
    int x;
    int y;
}Delta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

struct CompFunctor
{
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
    {
        return a.first > b.first;
    }
};

int GetParent(int v)
{
    int i;
    for (i = v; parent[i] != -1; i = parent[i]);
    return i;
}

void SetUnion(int u, int v)
{
    if (numSize[u] < numSize[v])
    {
        numSize[v] += numSize[u];
        parent[u] = v;
    }
    else
    {
        numSize[u] += numSize[v];
        parent[v] = u;
    }
}


void BFS(vector<vector<int>>& land, int y, int x, int areaNum, int height)
{
    queue<pair<int, int>> q;

    q.push({ y, x });
    visited[y][x] = areaNum;

    while (!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int y = f.first;
            int x = f.second;
            int ny = y+ Delta[i].y;
            int nx = x + Delta[i].x;

            if (ny < 0 || nx < 0 || ny >= land.size() || nx >= land[0].size())
                continue;

            if (visited[ny][nx] == 0 && abs(land[y][x] - land[ny][nx]) <= height)
            {
                visited[ny][nx] = areaNum;
                q.push({ ny, nx });
            }
        }
    }
}

int solution(vector<vector<int>> land, int height) 
{
    int answer = 0;
    int areaNum = 1;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, CompFunctor> pq;
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[i].size(); j++)
        {
            if (visited[i][j] == 0)
            {
                BFS(land, i, j, areaNum, height);
                areaNum++;
            }
        }
    }

    for (int y = 0; y < land.size(); y++)
    {
        for (int x = 0; x < land[y].size(); x++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + Delta[dir].x;
                int ny = y + Delta[dir].y;

                if (nx < 0 || ny < 0 || nx >= land[0].size() || ny >= land.size())
                    continue;

                if (visited[ny][nx] != visited[y][x])
                {
                    pq.push(make_pair(abs(land[ny][nx] - land[y][x]), make_pair(visited[ny][nx], visited[y][x])));
                }
            }
        }
    }

    
    areaNum--;

    fill(parent, parent + SIZE * SIZE, -1);
    fill(numSize, numSize + SIZE * SIZE, 1);

    for (int i = 0; i < areaNum - 1;)
    {
        pair<int, pair<int, int>> t = pq.top();
        pq.pop();

        int u = t.second.first;
        int v = t.second.second;

        int uParent = GetParent(u);
        int vParent = GetParent(v);

        if (uParent != vParent)
        {
            answer += t.first;
            SetUnion(uParent, vParent);
            i++;
        }
    }
    


    return answer;
}

int main()
{
    vector<vector<int>> land = {
        {10, 11, 10, 11},
        {2, 21, 20, 10},
        {1, 20, 21, 11},
        {2, 1, 2, 1}
    };

    int height = 1;

    cout << solution(land, height) << "\n";

    return 0;
}