#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int FindMax(vector<int> v, int j)
{
    int M = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (M < v[i] && i != j)
            M = v[i];
    }

    return M;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;

    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < land[i].size(); j++)
        {
            int M = FindMax(land[i - 1], j);
            land[i][j] += M;
        }
    }

    vector<int>::const_iterator it;
    
    for (it = land[land.size() - 1].begin(); it != land[land.size() - 1].end(); it++)
    {
        if (answer < *it)
            answer = *it;
    }

    return answer;
}

int main()
{
    vector<vector<int>> land = {
        {1, 2, 3, 5},
        {5, 6, 7, 8},
        {4, 3, 2, 1}
    };

    cout << solution(land) << "\n";

    return 0;
}