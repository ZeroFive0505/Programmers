#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> data)
{
    int answer = 0;
    sort(data.begin(), data.end());
    for (int i = 0; i < n; i++)
    {
        int x = data[i][0];
        int y = data[i][1];

        for (int j = i + 1; j < n; j++)
        {
            int xx = data[j][0];
            int yy = data[j][1];

            if (x == xx || y == yy) continue;

            bool Flag = true;
            for (int k = i + 1; k < j; k++)
            {
                int cx = data[k][0];
                int cy = data[k][1];
                if ((x < cx && cx < xx) && (min(y, yy) < cy && cy < max(y, yy)))
                {
                    Flag = false;
                    break;
                }
            }
            if (Flag == true) answer++;
        }
    }
    return answer;
}


int main()
{
    int n = 4;
    vector<vector<int>> data = {
        {0, 0},
        {1, 1},
        {0, 2},
        {2, 0}
    };

    return 0;
}