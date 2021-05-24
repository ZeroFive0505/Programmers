#include <iostream>
#include <string>
#include <vector>

using namespace std;

    

void DFS(vector<vector<int>>& coms, vector<bool>& visited, int vertex)
{
    visited[vertex] = true;
    for (int i = 0; i < coms[vertex].size(); i++)
    {
        if (!visited[i] && coms[vertex][i])
        {
            visited[i] = true;
            DFS(coms, visited, i);
        }
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
            DFS(computers, visited, i);
            answer++;
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