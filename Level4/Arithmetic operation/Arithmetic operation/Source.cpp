#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int SIZE = 200;

const int INF = 987654321;

int DP_MAX[SIZE][SIZE];
int DP_MIN[SIZE][SIZE];

int solution(vector<string> arr)
{
    int answer = 1;
    int num = arr.size() / 2 + 1;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            DP_MAX[i][j] = -INF;
            DP_MIN[i][j] = INF;
        }
    }

    for (int i = 0; i < num; i++)
    {
        DP_MAX[i][i] = atoi(arr[i * 2].c_str());
        DP_MIN[i][i] = atoi(arr[i * 2].c_str());
    }

    for (int calc = 1; calc < num; calc++)
    {
        for (int i = 0; i < num - calc; i++)
        {
            int j = calc + i;
            for (int k = i; k < j; k++)
            {
                if (arr[k * 2 + 1] == "-")
                {
                    DP_MAX[i][j] = max(DP_MAX[i][k] - DP_MIN[k + 1][j], DP_MAX[i][j]);
                    DP_MIN[i][j] = min(DP_MIN[i][k] - DP_MAX[k + 1][j], DP_MIN[i][j]);
                }
                else if (arr[k * 2 + 1] == "+")
                {
                    DP_MAX[i][j] = max(DP_MAX[i][k] + DP_MAX[k + 1][j], DP_MAX[i][j]);
                    DP_MIN[i][j] = min(DP_MIN[i][k] + DP_MIN[k + 1][j], DP_MIN[i][j]);
                }
            }
        }
    }

    answer = DP_MAX[0][num - 1];

    return answer;
}

int main()
{

    vector<string> arr = { "5", "-", "3", "+", "1", "+", "2", "-", "4" };

    cout << solution(arr) << "\n";

    return 0;
}