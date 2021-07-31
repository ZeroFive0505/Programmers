#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& computers, vector<bool>& visited, int u, int n)
{
    visited[u] = true;

    for (int v = 0; v < n; v++)
    {
        if (computers[u][v] == 1 && !visited[v])
            DFS(computers, visited, v, n);
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            answer++;
            DFS(computers, visited, i, n);
        }
    }

    return answer;
}

int main()
{
    int n = 3;
    vector<vector<int>> computers = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}
    };

    cout << solution(n, computers) << "\n";

    return 0;
}