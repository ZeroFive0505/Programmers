#include <iostream>
#include <string>
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

int row, col;

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

bool BoundaryCheck(int ny, int nx, vector<vector<int>>& board)
{
    if (ny < 0 || nx < 0)
        return true;
    else if (ny >= board.size() || nx >= board[0].size())
        return true;
    else
        return false;
}

int solution(vector<vector<int>> board) 
{
    int answer = INF;


    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < DIR; k++)
            {
                DIST[i][j][k] = INF;
            }
        }
    }

    priority_queue<sPoint, vector<sPoint>, sPointCmp> pq;

    for (int i = 0; i < DIR; i++)
    {
        DIST[0][0][i] = 0;
        pq.push(sPoint(0, 0, 0, i));
    }


    while (!pq.empty())
    {
        sPoint current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;
        int cost = current.cost;
        int prevDir = current.prevDir;

        for (int i = 0; i < DIR; i++)
        {
            int nx = x + Delta[i].x;
            int ny = y + Delta[i].y;

            if (abs(i - prevDir) == 2)
                continue;

            if (BoundaryCheck(ny, nx, board) || board[ny][nx] == 1)
                continue;



            int tempCost = 0;

            if (i != prevDir)
                tempCost = 600;
            else
                tempCost = 100;

            int nextCost = cost + tempCost;

            if (DIST[ny][nx][i] > nextCost)
            {
                DIST[ny][nx][i] = nextCost;
                pq.push(sPoint(nx, ny, nextCost, i));
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