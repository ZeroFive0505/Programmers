#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;

    if (triangle.size() > 2)
    {
        triangle[1][0] += triangle[0][0];
        triangle[1][1] += triangle[0][0];

        for (int i = 2; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0)
                    triangle[i][j] += triangle[i - 1][j];
                else if (j == triangle[i].size() - 1)
                    triangle[i][j] += triangle[i - 1][j - 1];
                else
                    triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }

        for (int i = 0; i < triangle[triangle.size() - 1].size(); i++)
        {
            answer = max(answer, triangle[triangle.size() - 1][i]);
        }
    }
    else
    {
        triangle[1][0] += triangle[0][0];
        triangle[1][1] += triangle[0][0];

        answer = max(triangle[1][0], triangle[1][1]);
    }

    return answer;
}

int main()
{
    vector<vector<int>> tri = {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5}
    };


    cout << solution(tri) << "\n";

    return 0;
}