#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    int answer = 0;
    vector<vector<int>> dists(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < fares.size(); i++)
    {
        int u = fares[i][0];
        int v = fares[i][1];
        int c = fares[i][2];

        dists[u][v] = c;
        dists[v][u] = c;
    }


    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dists[i][k] + dists[k][j] < dists[i][j])
                    dists[i][j] = dists[i][k] + dists[k][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
        dists[i][i] = 0;


    answer = dists[s][a] + dists[s][b];

    for (int i = 1; i <= n; i++)
    {
        if (dists[s][i] != INF && dists[i][a] != INF && dists[i][b] != INF)
            answer = min(answer, dists[s][i] + dists[i][a] + dists[i][b]);
    }

    return answer;
}

int main()
{
    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;


    vector<vector<int>> fares = {
        {4, 1, 10},
        {3, 5, 24},
        {5, 6, 2},
        {3, 1, 41},
        {5, 1, 24},
        {4, 6, 50},
        {2, 4, 66},
        {2, 3, 22},
        {1, 6, 25}
    };

    cout << solution(n, s, a, b, fares) << "\n";

    return 0;
}