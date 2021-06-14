#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int DIV = 1000000007;

const int SIZE = 101;

int cache[SIZE][SIZE];

int DP(int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    
    int& ret = cache[m][n];


    if(ret == 0)
        return 0;

    if (ret != -1)
        return ret;

    if (m == 1 && n == 1)
        return 1;


    return ret = (DP(m - 1, n) + DP(m, n - 1)) % DIV;
}

int solution(int m, int n, vector<vector<int>> puddles) 
{
    int answer = 0;

    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < puddles.size(); i++)
    {
        int y = puddles[i][0];
        int x = puddles[i][1];

        cache[y][x] = 0;
    }

    answer = DP(m, n);

    return answer;
}

int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {
        {2, 2}
    };

    cout << solution(m, n, puddles) << "\n";

    return 0;
}