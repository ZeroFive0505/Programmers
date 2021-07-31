#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) 
{
    int answer = 0;
    
    vector<vector<int>> edge(n, vector<int>(n, 0));

    for (int i = 0; i < edge_list.size(); i++)
    {
        int u = edge_list[i][0] - 1;
        int v = edge_list[i][1] - 1;

        edge[u][v] = 1;
        edge[v][u] = 1;
    }

    for (auto& i : gps_log)
        i--;

    vector<vector<int>> cache(n, vector<int>(n, INF));

    cache[0][gps_log.front()] = 0;

    for (int i = 1; i < gps_log.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            int additional = (gps_log[i] == j ? 0 : 1);

            for (int e = 0; e < edge[j].size(); e++)
            {
                if (edge[j][e] == 1)
                {
                    cache[i][j] = min(cache[i - 1][e] + additional, cache[i][j]);
                }
            }
        }
    }

    answer = cache[k - 1][gps_log[k - 1]];

    if (answer == INF)
        answer = -1;
    
    return answer;
}

int main()
{
    int n = 7;
    int m = 10;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 3},
        {2, 4},
        {3, 4},
        {3, 5},
        {4, 6},
        {5, 6},
        {5, 7},
        {6, 7}
    };

    vector<int> logs = { 1, 2, 4, 6, 5, 7 };

    cout << solution(n, m, edges, logs.size(), logs) << "\n";

    return 0;
}