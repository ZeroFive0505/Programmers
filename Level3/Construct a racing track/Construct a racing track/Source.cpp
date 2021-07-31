#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int SIZE = 26;

const int DIR = 4;

int DIST[SIZE][SIZE][DIR];

struct sDelta
{
    int x;
    int y;
} Delta[] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

const int INF = 987654321;


struct sPoint
{
    int x;
    int y;
    int cost;
    int prevDir;

    sPoint(int x, int y, int cost, int prevDir)
    {
        this->x = x;
        this->y = y;
        this->cost = cost;
        this->prevDir = prevDir;
    }
};

struct sPointCmp
{
    bool operator()(const sPoint& a, const sPoint& b)
    {
        return a.cost > b.cost;
    }
};


int solution(vector<vector<int>> board) 
{
    int answer = INF;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                DIST[i][j][k] = INF;
            }
        }
    }

    priority_queue<sPoint, vector<sPoint>, sPointCmp> pq;


    for (int i = 0; i < 4; i++)
    {
        DIST[0][0][i] = 0;
        pq.push(sPoint(0, 0, 0, i));
    }


    while (!pq.empty())
    {
        sPoint current = pq.top();
        pq.pop();

        int cx = current.x;
        int cy = current.y;
        int curCost = current.cost;
        int curDir = current.prevDir;

        for (int i = 0; i < DIR; i++)
        {
            int nx = cx + Delta[i].x;
            int ny = cy + Delta[i].y;
            int newDir = i;

            if (nx < 0 || ny < 0 || nx >= board[0].size() || ny >= board.size())
                continue;

            if (board[ny][nx] == 1)
                continue;

            if (abs(curDir - newDir) == 2)
                continue;

            int tempCost = 0;

            if (curDir == newDir)
                tempCost = 100;
            else if (curDir != newDir)
                tempCost = 600;


            if (DIST[ny][nx][newDir] > curCost + tempCost)
            {
                DIST[ny][nx][newDir] = curCost + tempCost;
                pq.push(sPoint(nx, ny, curCost + tempCost, newDir));
            }
        }
    }

    int row = board.size() - 1;
    int col = board[0].size() - 1;

    for (int i = 0; i < DIR; i++)
    {
        answer = min(answer, DIST[row][col][i]);
    }

    return answer;
}

int main()
{
    vector<vector<int>> board = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    cout << solution(board) << "\n";

    return 0;
}