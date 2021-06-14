#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 101;

const int COLUMN = 0;
const int BEAM = 1;

int BUILD[SIZE][SIZE][2];

bool CheckBoundary(int y, int x, int n)
{
    return (y >= 0 && x >= 0 && y <= n && x <= n);
}

bool ColCheck(int y, int x, int n)
{
    if (y == 0)
        return true;
    if (CheckBoundary(y - 1, x, n) && BUILD[y - 1][x][COLUMN])
        return true;
    if (CheckBoundary(y, x - 1, n) && BUILD[y][x - 1][BEAM])
        return true;
    if (CheckBoundary(y, x, n) && BUILD[y][x][BEAM])
        return true;
    return false;
}

bool BeamCheck(int y, int x, int n)
{
    if ((CheckBoundary(y, x - 1, n) && BUILD[y][x - 1][BEAM]
        && CheckBoundary(y, x + 1, n) && BUILD[y][x + 1][BEAM]))
        return true;
    if (CheckBoundary(y - 1, x, n) && BUILD[y - 1][x][COLUMN])
        return true;
    if (CheckBoundary(y - 1, x + 1, n) && BUILD[y - 1][x + 1][COLUMN])
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

        if (a == 1) // Beam
        {
            if (b == 1)
            {
                if (BeamCheck(y, x, n))
                    BUILD[y][x][BEAM] = 1;
            }
            else
            {
                BUILD[y][x][BEAM] = 0;

                if (BUILD[y][x - 1][BEAM] == 1)
                {
                    if (!BeamCheck(y, x - 1, n))
                    {
                        BUILD[y][x][BEAM] = 1;
                        continue;
                    }
                }

                if (BUILD[y][x + 1][BEAM] == 1)
                {
                    if (!BeamCheck(y, x + 1, n))
                    {
                        BUILD[y][x][BEAM] = 1;
                        continue;
                    }
                }

                if (BUILD[y][x][COLUMN] == 1)
                {
                    if (!ColCheck(y, x, n))
                    {
                        BUILD[y][x][BEAM] = 1;
                        continue;
                    }
                }


                if (BUILD[y][x + 1][COLUMN] == 1)
                {
                    if (!ColCheck(y, x + 1, n))
                    {
                        BUILD[y][x][BEAM] = 1;
                        continue;
                    }
                }
            }
        }
        else // Column
        {
            if (b == 1)
            {
                if (ColCheck(y, x, n))
                    BUILD[y][x][COLUMN] = 1;
            }
            else
            {
                BUILD[y][x][COLUMN] = 0;

                if (BUILD[y + 1][x][COLUMN])
                {
                    if (!ColCheck(y + 1, x, n))
                    {
                        BUILD[y][x][COLUMN] = 1;
                        continue;
                    }
                }


                if (BUILD[y + 1][x][BEAM])
                {
                    if (!BeamCheck(y + 1, x, n))
                    {
                        BUILD[y][x][COLUMN] = 1;
                        continue;
                    }
                }

                if (BUILD[y + 1][x - 1][BEAM])
                {
                    if (!BeamCheck(y + 1, x - 1, n))
                    {
                        BUILD[y][x][COLUMN] = 1;
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