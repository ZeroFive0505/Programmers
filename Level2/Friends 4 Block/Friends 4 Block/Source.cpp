#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sCoords
{
    int x;
    int y;
};

const sCoords Delta[] = {
    {1, 0},
    {0, 1},
    {1, 1}
};

bool BoundaryCheck(int y, int x, int m, int n)
{
    if (x < 0 || y < 0)
        return true;
    else if (y > m - 1 || x > n - 1)
        return true;
    else
        return false;
}

bool ComboCheck(int y, int x, vector<string>& board, char ch, vector<sCoords>& comboList, int m, int n)
{
    comboList.push_back({ x, y });

    for (int i = 0; i < 3; i++)
    {
        int nx = x + Delta[i].x;
        int ny = y + Delta[i].y;
        if (!BoundaryCheck(ny, nx, m, n) && board[ny][nx] != ch)
            break;
        else if(!BoundaryCheck(ny, nx, m, n) && board[ny][nx] == ch)
            comboList.push_back({ nx, ny });
    }

    if (comboList.size() >= 4)
        return true;
    else
        return false;
}

int solution(int m, int n, vector<string> board) 
{
    int answer = 0;
    while (1)
    {
        vector<sCoords> comboList;
        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x < n; x++)
            {
                vector<sCoords> temp;
                if (board[y][x] != '@')
                {
                    bool check = ComboCheck(y, x, board, board[y][x], temp, m, n);
                    if (check)
                        comboList.insert(comboList.end(), temp.begin(), temp.end());
                    else
                        temp.clear();
                }
            }
        }

        if (comboList.size() >= 4)
        {
            for (int i = 0; i < comboList.size(); i++)
            {
                int x = comboList[i].x;
                int y = comboList[i].y;

                if (board[y][x] != '@')
                {
                    board[y][x] = '@';
                    answer++;
                }
            }
        }
        else
            break;

        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (board[y][x] == '@')
                {
                    int lim = y;
                    while (lim > 0)
                    {
                        board[lim][x] = board[lim - 1][x];
                        board[lim - 1][x] = '@';
                        lim--;
                    }
                }
            }
        }
    }


    return answer;
}

int main()
{
    int m = 5;
    int n = 6;
    vector<string> b = {
        "AAAAAA",
        "BBAATB",
        "BBAATB",
        "JJJTAA",
        "JJJTAA"
    };

    cout << solution(m, n, b) << "\n";

    return 0;
}