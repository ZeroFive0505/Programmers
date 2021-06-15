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
    queue<sPoint> q;

    vector<vector<bool>> visited(4, vector<bool>(4, false));

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

            if (nr < 0 || nr > 3 || nc < 0 || nc > 3)
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
        vector<sPoint> cardList;
        for (int i = 0; i < BOARD.size(); i++)
        {
            for (int j = 0; j < BOARD[i].size(); j++)
            {
                if (BOARD[i][j] == card)
                    cardList.push_back({ i, j, 0 });
            }
        }


        if (cardList.empty())
            continue;

        int first = BFS(current, cardList[0]) + BFS(cardList[0], cardList[1]) + 2;
        int second = BFS(current, cardList[1]) + BFS(cardList[1], cardList[0]) + 2;

        for (int i = 0; i < 2; i++)
            BOARD[cardList[i].row][cardList[i].col] = 0;

        ret = min(ret, first + Permutate(cardList[1]));
        ret = min(ret, second + Permutate(cardList[0]));

        for (int i = 0; i < 2; i++)
            BOARD[cardList[i].row][cardList[i].col] = card;

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