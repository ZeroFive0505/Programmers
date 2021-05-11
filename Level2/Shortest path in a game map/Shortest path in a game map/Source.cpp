#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct sCoordinates
{
	int x;
	int y;
	int dist;
};

int solution(vector<vector<int>> maps)
{
	queue<sCoordinates> q;
	vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
	int answer = -1;

	int deltaY[4] = { -1, 0, 1, 0 };
	int deltaX[4] = { 0, 1, 0, -1 };

	int n = maps.size();
	int m = maps[0].size();

	visited[0][0] = true;

	q.push({ 0, 0, 1 });
	while (!q.empty())
	{

		sCoordinates current = q.front();
		q.pop();

		int curX = current.x;
		int curY = current.y;
		int curDist = current.dist;

		if (current.y == maps.size() - 1 && current.x == maps[0].size() - 1)
			answer = curDist;

		for (int i = 0; i < 4; i++)
		{
			int nx = current.x + deltaX[i];
			int ny = current.y + deltaY[i];

			if (ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size())
				continue;
			
			if (maps[ny][nx] == 0)
				continue;

			if (visited[ny][nx])
				continue;

			q.push({ nx, ny, curDist + 1 });
			visited[ny][nx] = true;
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> maps = {
		{1, 0, 1, 1, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{0, 0, 0, 0, 1},
	};

	cout << solution(maps) << "\n";

	return 0;
}