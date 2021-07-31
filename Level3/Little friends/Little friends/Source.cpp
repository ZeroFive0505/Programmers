#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <ctype.h>
#include <vector>

using namespace std;

struct sDelta
{
    int r;
    int c;
} Delta[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

struct sPos
{
    int r;
    int c;
    int dir;
};

int M, N;

const int INF = 987654321;

vector<string> B;

map<char, sPos> hashMap;

sPos BFS(sPos src, char ch)
{
    vector<vector<int>> turns(M, vector<int>(N, INF));

    turns[src.r][src.c] = 0;

    src.dir = -1;

    queue<sPos> q;

    q.push(src);

    bool not_first = false;

    while (!q.empty())
    {
        sPos cur = q.front();
        q.pop();

        if (not_first && B[cur.r][cur.c] == ch)
            return cur;

        not_first = true;

        for (int i = 0; i < 4; i++)
        {
            int nr = cur.r + Delta[i].r;
            int nc = cur.c + Delta[i].c;

            int nextDir = i;

            int nextTurn = turns[cur.r][cur.c];

            if (cur.dir != -1 && cur.dir != nextDir)
                nextTurn++;

            if (nr < 0 || nr >= M || nc < 0 || nc >= N)
                continue;

            if (nextTurn >= 2)
                continue;

            if (B[nr][nc] != '.' && B[nr][nc] != ch)
                continue;

            if (turns[nr][nc] >= nextTurn)
            {
                q.push({ nr, nc, nextDir });
                turns[nr][nc] = nextTurn;
            }
        }
    }
    

    return { -1, -1 };
}

string solution(int m, int n, vector<string> board)
{
    string answer;

    M = m;
    N = n;
    B = board;


    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (isalpha(B[i][j]))
            {
                hashMap[B[i][j]] = { i, j };
            }
        }
    }


    while (1)
    {
        bool canRemove = false;
        for (const auto& iter : hashMap)
        {
            char ch = iter.first;
            sPos src = iter.second;
            sPos dest = BFS(src, ch);

            if (dest.r != -1 && dest.c != -1)
            {
                B[src.r][src.c] = '.';
                B[dest.r][dest.c] = '.';
                hashMap.erase(iter.first);
                answer += ch;
                canRemove = true;
                break;
            }
        }

        if (canRemove)
            continue;

        if (hashMap.empty())
            return answer;
        else
            return "IMPOSSIBLE";
    }
}

int main()
{
    int m, n;

    m = 3;
    n = 3;

    vector<string> board = { "DBA", "C*A", "CDB" };

    cout << solution(m, n, board) << "\n";

    return 0;
}