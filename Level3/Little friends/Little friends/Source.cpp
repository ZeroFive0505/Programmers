#include <iostream>
#include <string>
#include <map>
#include <queue>
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
    queue<Pos> q;
    vector<vector<int>> turns(M, vector<int>(N, INF));

    v.dir = -1;
    q.push(v);
    turns[v.r][v.c] = 0;

    bool not_first = false;

    while (!q.empty())
    {
        Pos now = q.front();
        q.pop();

        if (not_first && B[now.r][now.c] == ch)
            return { now.r, now.c };
        not_first = true;

        for (int i = 0; i < 4; i++)
        {
            int nextR = now.r + Delta[i].r;
            int nextC = now.c + Delta[i].c;

            int nextDir = i;

            int next_turn = turns[now.r][now.c];

            if (now.dir != -1 && now.dir != nextDir)
                next_turn++;

            if (nextR < 0 || nextR >= M || nextC < 0 || nextC >= N)
                continue;

            if (next_turn >= 2)
                continue;

            if (B[nextR][nextC] != '.' && B[nextR][nextC] != ch)
                continue;

            if (turns[nextR][nextC] >= next_turn)
            {
                q.push({ nextR, nextC, nextDir });
                turns[nextR][nextC] = next_turn;
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
            if (board[i][j] >= 'A' && board[i][j] <= 'Z')
                hashMap[board[i][j]] = { i, j };
        }
    }

    while (1)
    {
        bool canRemove = false;

        for (const auto& letter : hashMap)
        {
            char ch = letter.first;
            Pos start = letter.second;
            Pos dest = BFS(start, ch);

            if (dest.r != -1 && dest.c != -1)
            {
                canRemove = true;
                B[start.r][start.c] = '.';
                B[dest.r][dest.c] = '.';
                answer += ch;
                hashMap.erase(ch);
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


    return answer;
}

int main()
{
    int m, n;

    m = 4;
    n = 4;

    vector<string> board = { "FGHEI", "BAB..", "D.C*.", "CA..I", "DFHGE" };

    cout << solution(m, n, board) << "\n";

    return 0;
}