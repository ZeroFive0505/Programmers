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

struct Pos
{
    int r;
    int c;
    int dir;
};

int M, N;

const int INF = 987654321;

vector<string> B;

map<char, Pos> hashMap;

Pos BFS(Pos v, char ch)
{
    vector<vector<int>> turnCnts(M, vector<int>(N, INF));

    v.dir = -1;
    queue<Pos> q;
    q.push(v);
    turnCnts[v.r][v.c] = 0;

    bool not_first = false;

    auto check = [&](const int r, const int c) {
        if (r >= M || c >= N)
            return true;
        else if (r < 0 || c < 0)
            return true;
        else
            return false;
    };

    while (!q.empty())
    {
        Pos current = q.front();
        q.pop();

        if (not_first && B[current.r][current.c] == ch)
            return { current.r, current.c };

        not_first = true;

        for (int i = 0; i < 4; i++)
        {
            int nextR = current.r + Delta[i].r;
            int nextC = current.c + Delta[i].c;

            int nextDir = i;

            int turn = turnCnts[current.r][current.c];

            if (current.dir != -1 && current.dir != nextDir)
                turn++;

            if (check(nextR, nextC))
                continue;

            if (turn >= 2)
                continue;

            if (B[nextR][nextC] != '.' && B[nextR][nextC] != ch)
                continue;

            if (turnCnts[nextR][nextC] >= turn)
            {
                q.push({ nextR, nextC, nextDir });
                turnCnts[nextR][nextC] = turn;
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

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isalpha(board[i][j]))
                hashMap[board[i][j]] = { i, j };
        }
    }

    while (1)
    {
        bool removal = false;


        for (const auto& kv : hashMap)
        {
            char ch = kv.first;
            Pos start = kv.second;

            Pos dest = BFS(start, ch);

            if (dest.r != -1 && dest.c != -1)
            {
                B[dest.r][dest.c] = '.';
                B[start.r][start.c] = '.';
                hashMap.erase(ch);
                answer.push_back(ch);
                removal = true;
                break;
            }
        }

        if (removal)
            continue;

        if (hashMap.empty())
            return answer;
        else
            return "IMPOSSIBLE";
    }

    return answer;
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