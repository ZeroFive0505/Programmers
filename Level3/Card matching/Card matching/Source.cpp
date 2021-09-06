#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> BOARD;

const int INF = 987654321;

struct sPoint
{
    int row;
    int col;
    int cnt;

    bool operator==(const sPoint& rhs) const
    {
        return row == rhs.row && col == rhs.col;
    }
};

struct sDelta
{
    int row;
    int col;
}Delta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int BFS(const sPoint& start, const sPoint& end)
{
    vector<vector<bool>> visited(BOARD.size(), vector<bool>(BOARD[0].size(), false));
    visited[start.row][start.col] = true;

    queue<sPoint> q;

    q.push(start);

    while (!q.empty())
    {
        sPoint current = q.front();
        q.pop();

        if (current == end)
            return current.cnt;

        for (int i = 0; i < 4; i++)
        {
            int nr = current.row + Delta[i].row;
            int nc = current.col + Delta[i].col;

            if (nr < 0 || nc < 0 || nr >= BOARD.size() || nc >= BOARD[0].size())
                continue;

            if (!visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({ nr, nc, current.cnt + 1 });
            }


            for (int j = 0; ; j++)
            {
                if (BOARD[nr][nc] != 0)
                    break;

                if (nr + Delta[i].row < 0 || nc + Delta[i].col < 0 || nr + Delta[i].row >= BOARD.size() ||
                    nc + Delta[i].col >= BOARD[0].size())
                    break;

                nr += Delta[i].row;
                nc += Delta[i].col;
            }

            if (!visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({ nr, nc, current.cnt + 1 });
            }
        }
    }

    return INF;
}

int Permute(sPoint current)
{
    int ret = INF;

    for (int cardNum = 1; cardNum < 7; cardNum++)
    {
        vector<sPoint> cardPairs;

        for (int i = 0; i < BOARD.size(); i++)
        {
            for (int j = 0; j < BOARD[0].size(); j++)
            {
                if (cardNum == BOARD[i][j])
                    cardPairs.push_back({ i, j, 0 });
            }
        }

        if (cardPairs.empty())
            continue;

        int first = BFS(current, cardPairs[0]) + BFS(cardPairs[0], cardPairs[1]) + 2;
        int second = BFS(current, cardPairs[1]) + BFS(cardPairs[1], cardPairs[0]) + 2;

        for (int i = 0; i < cardPairs.size(); i++)
            BOARD[cardPairs[i].row][cardPairs[i].col] = 0;

        ret = min(ret, first + Permute(cardPairs[1]));
        ret = min(ret, second + Permute(cardPairs[0]));

        for (int i = 0; i < cardPairs.size(); i++)
            BOARD[cardPairs[i].row][cardPairs[i].col] = cardNum;
    }

    if (ret == INF)
        return 0;
    return ret;
}

int solution(vector<vector<int>> board, int r, int c)
{
    BOARD = board;
    return Permute({ r, c, 0 });
}

int main()
{
    vector<vector<int>> board = {
        {1, 0, 0, 3},
        {2, 0, 0, 0},
        {0, 0, 0, 2},
        {3, 0, 1, 0}
    };

    int r = 1;
    int c = 0;

    cout << solution(board, r, c) << "\n";

    return 0;
}