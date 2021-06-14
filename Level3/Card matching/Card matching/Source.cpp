#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 987654321;

vector<vector<int>> BOARD;

struct sPoint
{
    int row;
    int col;
    int cnt;

    bool operator==(const sPoint& rhs)
    {
        if (this->row == rhs.row && this->col == rhs.col)
            return true;
        else
            return false;
    }
};

const int CARDS = 7;
const int SIZE = 4;

struct sDelta
{
    int row;
    int col;
} Delta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int BFS(sPoint current, sPoint dest)
{
    vector<vector<bool>> visited(4, vector<bool>(4, false));

    queue<sPoint> q;

    q.push(current);

    while (!q.empty())
    {
        sPoint cur = q.front();
        q.pop();

        if (cur == dest)
            return cur.cnt;

        for (int i = 0; i < 4; i++)
        {
            int nr = cur.row + Delta[i].row;
            int nc = cur.col + Delta[i].col;

            if (nr < 0 || nc < 0 || nr > 3 || nc > 3)
                continue;

            if (!visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({ nr, nc, cur.cnt + 1 });
            }

            for (int j = 0; ; j++)
            {
                if (BOARD[nr][nc] != 0)
                    break;

                if (nr + Delta[i].row < 0 || nr + Delta[i].row > 3 ||
                    nc + Delta[i].col < 0 || nc + Delta[i].col > 3)
                    break;

                nr += Delta[i].row;
                nc += Delta[i].col;
            }

            if (!visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({ nr, nc, cur.cnt + 1 });
            }
        }
    }

    return INF;
}

int Permutate(sPoint current)
{
    int ret = INF;

    for (int card = 1; card < CARDS; card++)
    {
        vector<sPoint> cards;

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (BOARD[i][j] == card)
                    cards.push_back({ i, j, 0 });
            }
        }

        if (cards.empty())
            continue;

        int first = BFS(current, cards[0]) + BFS(cards[0], cards[1]) + 2;
        int second = BFS(current, cards[1]) + BFS(cards[1], cards[0]) + 2;

        for (int i = 0; i < 2; i++)
            BOARD[cards[i].row][cards[i].col] = 0;

        ret = min(ret, first + Permutate(cards[1]));
        ret = min(ret, second + Permutate(cards[0]));

        for (int i = 0; i < 2; i++)
            BOARD[cards[i].row][cards[i].col] = card;
    }

    if (ret == INF)
        return 0;

    return ret;
}

int solution(vector<vector<int>> board, int r, int c)
{
    BOARD = board;
    return Permutate({ r, c, 0 });
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