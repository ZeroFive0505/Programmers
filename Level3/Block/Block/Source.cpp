#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

vector<vector<int>> Board;

int N;

struct sDelta
{
    int x;
    int y;
}Delta[] = {
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

    bool IsValid()
    {
        if (x < 0 || x2 < 0 || y < 0 || y2 < 0 || x >= N || x2 >= N || y >= N || y2 >= N)
            return false;
        
        if (Board[y][x] || Board[y2][x2])
            return false;

        return true;
    }

    sRobot Move(int d)
    {
        return sRobot(x + Delta[d].x, y + Delta[d].y, x2 + Delta[d].x, y2 + Delta[d].y);
    }

    pair<sRobot, sRobot> Rotate(int d)
    {
        return make_pair(sRobot(x, y, x + Delta[d].x, y + Delta[d].y), sRobot(x2, y2, x2 + Delta[d].x, y2 + Delta[d].y));
    }

    bool IsFinished()
    {
        return x == N - 1 && y == N - 1 || x2 == N - 1 && y2 == N - 1;
    }

    bool operator==(const sRobot& rhs) const
    {
        return tie(x, y, x2, y2) == tie(rhs.x, rhs.y, rhs.x2, rhs.y2) ||
            tie(x, y, x2, y2) == tie(rhs.x2, rhs.y2, rhs.x, rhs.y);
    }

    bool operator<(const sRobot& rhs) const
    {
        return tie(x, y, x2, y2) < tie(rhs.x, rhs.y, rhs.x2, rhs.y2);
    }
};

map<sRobot, int> Dist;

vector<sRobot> GetMoved(sRobot& r)
{
    vector<sRobot> moved;

    for (int i = 0; i < 4; i++)
    {
        moved.push_back(r.Move(i));
    }

    return moved;
}


vector<sRobot> GetRotated(sRobot& r)
{
    vector<sRobot> rotated;

    for (int i = 0; i < 4; i++)
    {
        if (r.Move(i).IsValid())
        {
            pair<sRobot, sRobot> rot = r.Rotate(i);
            rotated.push_back(rot.first);
            rotated.push_back(rot.second);
        }
    }

    return rotated;
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

        vector<sRobot> movement[2] = { GetMoved(cur), GetRotated(cur) };

        for (int i = 0; i < 2; i++)
        {
            for (auto it : movement[i])
            {
                if (Dist.find(it) == Dist.end() && it.IsValid())
                {
                    q.push(it);
                    Dist[it] = curDist + 1;
                }
            }
        }
    }

    return -1;
}


int solution(vector<vector<int>> board) 
{
    int answer = 0;
    N = board.size();
    Board = board;
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