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
    int x1;
    int y1;
    int x2;
    int y2;

    sRobot(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2)
    {

    }

    bool IsValid() const
    {
        if (x1 >= 0 && x1 < N && y1 >= 0 && y1 < N && x2 >= 0 && x2 < N && y2 >= 0 && y2 < N && !Board[y1][x1] && !Board[y2][x2])
            return true;
        else
            return false;
    }

    bool IsFinished() const
    {
        if (x1 == N - 1 && y1 == N - 1 || x2 == N - 1 && y2 == N - 1)
            return true;
        else
            return false;
    }

    sRobot Move(int d)
    {
        return sRobot(x1 + Delta[d].x, y1 + Delta[d].y, x2 + Delta[d].x, y2 + Delta[d].y);
    }

    pair<sRobot, sRobot> Rotate(int d)
    {
        return make_pair(sRobot(x1, y1, x1 + Delta[d].x, y1 + Delta[d].y), sRobot(x2, y2, x2 + Delta[d].x, y2 + Delta[d].y));
    }

    bool operator==(const sRobot& rhs) const
    {
        return tie(x1, y1, x2, y2) == tie(rhs.x1, rhs.y1, rhs.x2, rhs.y2) ||
            tie(x1, y1, x2, y2) == tie(rhs.x2, rhs.y2, rhs.x1, rhs.y1);
    }

    bool operator<(const sRobot& rhs) const
    {
        return tie(x1, y1, x2, y2) < tie(rhs.x1, rhs.y1, rhs.x2, rhs.y2);
    }
};

map<sRobot, int> hashMap;

vector<sRobot> GetMoved(sRobot& current)
{
    vector<sRobot> ret;

    for (int i = 0; i < 4; i++)
    {
        if (current.Move(i).IsValid())
            ret.push_back(current.Move(i));
    }

    return ret;
}

vector<sRobot> GetRotated(sRobot& current)
{
    vector<sRobot> ret;

    for (int i = 0; i < 4; i++)
    {
        if (current.Move(i).IsValid())
        {
            pair<sRobot, sRobot> temp = current.Rotate(i);
            ret.push_back(temp.first);
            ret.push_back(temp.second);
        }
    }

    return ret;
}

int BFS(sRobot robot)
{
    hashMap[robot] = 0;
    queue<sRobot> q;

    q.push(robot);

    while (!q.empty())
    {
        sRobot cur = q.front();
        q.pop();

        int curDist = hashMap[cur];

        if (cur.IsFinished())
            return curDist;

        vector<sRobot> next[2] = { GetMoved(cur), GetRotated(cur) };

        for (int i = 0; i < 2; i++)
        {
            for (sRobot& r: next[i])
            {
                if (hashMap.find(r) == hashMap.end() && r.IsValid())
                {
                    hashMap[r] = curDist + 1;
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