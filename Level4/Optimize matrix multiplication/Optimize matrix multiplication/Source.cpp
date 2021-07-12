#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 210;

int cache[SIZE][SIZE];

const int INF = 987654321;

int solution(vector<vector<int>> matrix_sizes)
{
    int answer = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
                cache[i][j] = 0;
            else
                cache[i][j] = INF;
        }
    }

    for (int i = 0; i < matrix_sizes.size(); i++)
    {
        for (int left = 0; left < matrix_sizes.size(); left++)
        {
            int right = left + i;

            if (right >= matrix_sizes.size())
                break;

            for (int k = left; k < right; k++)
            {
                cache[left][right] = min(cache[left][right], 
                    cache[left][k] + cache[k + 1][right] + matrix_sizes[left][0] * matrix_sizes[k + 1][0] * matrix_sizes[right][1]);
            }
        }
    }

    answer = cache[0][matrix_sizes.size() - 1];
    return answer;
}


int main()
{
    vector<vector<int>> matrix_sizes = {
        {5, 3},
        {3, 10},
        {10, 6}
    };

    cout << solution(matrix_sizes) << "\n";

    return 0;
}