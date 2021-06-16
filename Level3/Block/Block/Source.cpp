#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

int N;

vector<vector<int>> Board;

struct sDelta
{
    int x;
    int y;
} Delta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

struct sRobot
{
    int x;
    int y;
    int x2;
    int y2;

    sRobot(int x, int y, int x2, int y2) : x(x), y(y), x2(x2), y2(y2) {}

    sRobot Move(int d)
    {
        return sRobot(x + Delta[d].x, y + Delta[d].y, x2 + Delta[d].x, y2 + Delta[d].y);
    }

    pair<sRobot, sRobot> Rotate(int d)
    {
        return make_pair( sRobot(x, y, x + Delta[d].x, y + Delta[d].y), sRobot(x2, y2, x2 + Delta[d].x, y2 + Delta[d].y) );
    }

    bool IsValid()
    {
        return x >= 0 && y >= 0 && x2 >= 0 && y2 >= 0 &&
            x < N && y < N && x2 < N && y2 < N && !Board[y][x] && !Board[y2][x2];
    }

    bool IsFinished()
    {
        return x == N - 1 && y == N - 1 || x2 == N - 1 && y2 == N - 1;
    }
};

bool operator==(sRobot a, sRobot b)
{
    return tie(a.x, a.y, a.x2, a.y2) == tie(b.x, b.y, b.x2, b.y2) ||
        tie(a.x, a.y, a.x2, a.y2) == tie(b.x2, b.y2, b.x, b.y);
}

bool operator<(sRobot a, sRobot b)
{
    return tie(a.x, a.y, a.x2, a.y2) < tie(b.x, b.y, b.x2, b.y2);
}

map<sRobot, int> Dist;

vector<sRobot> GetMoved(sRobot& r)
{
    vector<sRobot> ret;

    for (int i = 0; i < 4; i++)
        ret.push_back(r.Move(i));

    return ret;
}

vector<sRobot> GetRotated(sRobot& r)
{
    vector<sRobot> ret;

    for (int i = 0; i < 4; i++)
    {
        if (r.Move(i).IsValid())
        {
            pair<sRobot, sRobot> res = r.Rotate(i);
            ret.push_back(res.first);
            ret.push_back(res.second);
        }
    }

    return ret;
}

int BFS(sRobot r)
{
    Dist[r] = 0;

    queue<sRobot> q;

    q.push(r);

    while (!q.empty())
    {
        sRobot cur = q.front();
        q.pop();

        int curDist = Dist[cur];

        if (cur.IsFinished())
            return curDist;

        vector<sRobot> next[2] = { GetMoved(cur), GetRotated(cur) };

        for (int i = 0; i < 2; i++)
        {
            for (sRobot r : next[i])
            {
                if (Dist.find(r) == Dist.end() && r.IsValid())
                {
                    Dist[r] = curDist + 1;
                    q.push(r);
                }
            }
        }
    }

    return -1;
}

int solution(vector<vector<int>> board) 
{
    int answer = 0;
    Board = board;
    N = board.size();
    answer = BFS(sRobot(0, 0, 1, 0));
    return answer;
}

int main()
{
    vector<vector<int>> board = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    cout << solution(board) << "\n";

    return 0;
}