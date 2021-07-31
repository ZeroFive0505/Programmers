#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 101;

const int COLUMN = 0;
const int BEAM = 1;

int BUILD[SIZE][SIZE][2];

bool CheckBoundary(const int x, const int y, const int n)
{
    if (y >= 0 && x >= 0 && x <= n && y <= n)
        return true;
    else
        return false;
}

bool BeamCheck(const int x, const int y, const int n)
{
    if (CheckBoundary(x - 1, y, n) && BUILD[y][x - 1][BEAM] && 
        CheckBoundary(x + 1, y, n) && BUILD[y][x + 1][BEAM])
        return true;

    if (CheckBoundary(y - 1, x, n) && BUILD[y - 1][x][COLUMN])
        return true;

    if (CheckBoundary(y - 1, x + 1, n) && BUILD[y - 1][x + 1][COLUMN])
        return true;

    return false;
}

bool ColCheck(const int x, const int y, const int n)
{
    if (y == 0)
        return true;

    if (CheckBoundary(x, y - 1, n) && BUILD[y - 1][x][COLUMN])
        return true;

    if (CheckBoundary(x - 1, y, n) && BUILD[y][x - 1][BEAM])
        return true;

    if (CheckBoundary(x, y, n) && BUILD[y][x][BEAM])
        return true;

    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];

        if (a == 0) // Column
        {
            if (b == 1)
            {
                if (ColCheck(x, y, n))
                    BUILD[y][x][COLUMN] = 1;
            }
            else
            {
                BUILD[y][x][COLUMN] = 0;

                if (BUILD[y + 1][x][COLUMN] == 1)
                {
                    if (!ColCheck(x, y + 1, n))
                    {
                        BUILD[y][x][COLUMN] = 1;
                        continue;
                    }
                }

                if (BUILD[y + 1][x][BEAM] == 1)
                {
                    if (!BeamCheck(x, y + 1, n))
                    {
                        BUILD[y][x][COLUMN] = 1;
                        continue;
                    }
                }

                if (BUILD[y + 1][x - 1][BEAM] == 1)
                {
                    if (!BeamCheck(x - 1, y + 1, n))
                    {
                        BUILD[y][x][COLUMN] = 1;
                        continue;
                    }
                }
            }
        }
        else // Beam
        {
            if (b == 1)
            {
                if (BeamCheck(x, y, n))
                    BUILD[y][x][BEAM] = 1;
            }
            else
            {
                BUILD[y][x][BEAM] = 0;

                if (BUILD[y][x - 1][BEAM] == 1)
                {
                    if (!BeamCheck(x - 1, y, n))
                    {
                        BUILD[y][x][BEAM] = 1;
                        continue;
                    }
                }

                if (BUILD[y][x + 1][BEAM] == 1)
                {
                    if (!BeamCheck(x + 1, y, n))
                    {
                        BUILD[y][x][BEAM] = 1;
                        continue;
                    }
                }

                if (BUILD[y][x][COLUMN] == 1)
                {
                    if (!ColCheck(x, y, n))
                    {
                        BUILD[y][x][BEAM] = 1;
                        continue;
                    }
                }

                if (BUILD[y][x + 1][COLUMN] == 1)
                {
                    if (!ColCheck(x + 1, y, n))
                    {
                        BUILD[y][x][BEAM] = 1;
                        continue;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (BUILD[j][i][COLUMN])
                answer.push_back({ i, j, COLUMN });

            if (BUILD[j][i][BEAM])
                answer.push_back({ i, j, BEAM });
        }
    }


    return answer;
}

int main()
{
    int n = 5;

    vector<vector<int>> build_frame = {
        {1, 0, 0, 1},
        {1, 1, 1, 1},
        {2, 1, 0, 1},
        {2, 2, 1, 1},
        {5, 0, 0, 1},
        {5, 1, 0, 1},
        {4, 2, 1, 1},
        {3, 2, 1, 1}
    };

    vector<vector<int>> ans = solution(n, build_frame);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}