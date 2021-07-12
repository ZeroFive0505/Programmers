#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

enum class Position
{
    EMPTY,
    PARTITION
};

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

struct sSit
{
    int x;
    int y;
    Position pos;

    sSit(int x, int y, Position pos) : x(x), y(y), pos(pos) {}
};

bool BFS(vector<string>& v, int y, int x)
{
    queue<sSit> q;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + Delta[i].y;
        int nx = x + Delta[i].x;

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
            continue;

        if (v[ny][nx] == 'P')
            return false;

        if (v[ny][nx] == 'O')
        {
            q.push(sSit(nx, ny, Position::EMPTY));
        }
        else if (v[ny][nx] == 'X')
        {
            q.push(sSit(nx, ny, Position::PARTITION));
        }
    }


    while (!q.empty())
    {
        sSit cur = q.front();
        q.pop();

        int cx = cur.x;
        int cy = cur.y;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + Delta[i].x;
            int ny = cy + Delta[i].y;

            if (nx == x && ny == y)
                continue;

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;

            if (v[ny][nx] == 'P' && cur.pos == Position::EMPTY)
                return false;
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) 
{
    vector<int> answer;

    for (int i = 0; i < places.size(); i++)
    {
        vector<string> v = places[i];
        bool check = true;
        for (int j = 0; j < v.size(); j++)
        {
            for (int k = 0; k < v[j].size(); k++)
            {
                if (v[j][k] == 'P')
                {
                    check = BFS(v, j, k);
                }

                if (!check)
                    break;
            }

            if (!check)
                break;
        }

        if (check)
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}

int main()
{
    vector<vector<string>> places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };

    vector<int> ans = solution(places);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}