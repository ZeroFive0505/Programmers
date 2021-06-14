#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int MOD = 20170805;

const int SIZE = 501;

int RIGHT[SIZE][SIZE];
int DOWN[SIZE][SIZE];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) 
{
    int answer = 0;
    memset(RIGHT, 0, sizeof(RIGHT));
    memset(DOWN, 0, sizeof(DOWN));
    RIGHT[1][1] = DOWN[1][1] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (city_map[i - 1][j - 1] == 0)
            {
                RIGHT[i][j] = (RIGHT[i][j] + RIGHT[i][j - 1] + DOWN[i - 1][j]) % MOD;
                DOWN[i][j] = (DOWN[i][j] + RIGHT[i][j - 1] + DOWN[i - 1][j]) % MOD;
            }
            else if (city_map[i - 1][j - 1] == 1)
            {
                RIGHT[i][j] = 0;
                DOWN[i][j] = 0;
            }
            else
            {
                RIGHT[i][j] = RIGHT[i][j - 1];
                DOWN[i][j] = DOWN[i - 1][j];
            }
        }
    }

    answer = (RIGHT[m][n - 1] + DOWN[m - 1][n]) % MOD;

    return answer;
}

int main()
{
    int m = 3;
    int n = 6;

    vector<vector<int>> city_map = {
        {0, 2, 0, 0, 0, 2},
        {0, 0, 2, 0, 1, 0},
        {1, 0, 0, 2, 2, 0}
    };

    cout << solution(m, n, city_map) << "\n";

    return 0;
}