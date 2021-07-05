#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<vector<int>> Board;

bool CanFill(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (Board[i][col] != 0)
            return false;
    }

    return true;
}

bool Find(int row, int col, int h, int w)
{
    int emptyCnt = 0;
    int lastValue = -1;

    for (int r = row; r < row + h; r++)
    {
        for (int c = col; c < col + w; c++)
        {
            if (Board[r][c] == 0)
            {
                if (!CanFill(r, c))
                    return false;
                emptyCnt++;
                if (emptyCnt > 2)
                    return false;
            }
            else
            {
                if (lastValue != -1 && lastValue != Board[r][c])
                    return false;
                lastValue = Board[r][c];
            }
        }
    }

    for (int r = row; r < row + h; r++)
    {
        for (int c = col; c < col + w; c++)
        {
            Board[r][c] = 0;
        }
    }

    return true;
}

int solution(vector<vector<int>> board) 
{
    Board = board;
    N = board.size();
    int answer = 0;
    int cnt;

    do
    {
        cnt = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i <= N - 2 && j <= N - 3 && Find(i, j, 2, 3))
                {
                    cnt++;
                }
                else if(i <= N - 3 && j <= N - 2 && Find(i, j, 3, 2))
                {
                    cnt++;
                }
            }
        }

        answer += cnt;

    } while (cnt);

    return answer;
}

int main()
{
    vector<vector<int>> board = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,4,4,0,0,0},
        {0,0,0,0,3,0,4,0,0,0},
        {0,0,0,2,3,0,0,0,5,5},
        {1,2,2,2,3,3,0,0,0,5},
        {1,1,1,0,0,0,0,0,0,5}
    };

    cout << solution(board) << "\n";

    return 0;
}