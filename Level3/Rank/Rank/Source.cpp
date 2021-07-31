#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;

    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < results.size(); i++)
    {
        int u = results[i][0];
        int v = results[i][1];

        graph[u][v] = true;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = true;
            }
        }
    }


    
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] || graph[j][i])
                cnt++;
        }

        if (cnt == n - 1)
            answer++;
    }

    return answer;
}

int main()
{
    int n = 5;
    vector<vector<int>> res = {
        {4, 3},
        {4, 2},
        {3, 2},
        {1, 2},
        {2, 5}
    };


    cout << solution(n, res) << "\n";

    return 0;
}