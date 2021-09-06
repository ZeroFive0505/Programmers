#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int M, N;

bool BoundaryCheck(int y, int x)
{
	if (y < 0 || x < 0 || y >= M || x >= N)
		return true;
	else
		return false;
}

int DFS(vector<vector<int>>& picture, int y, int x, vector<vector<bool>>& visited, int color)
{
	visited[y][x] = true;
	int cnt = 1;

	if (!BoundaryCheck(y + 1, x) && !visited[y + 1][x] && picture[y + 1][x] == color)
		cnt += DFS(picture, y + 1, x, visited, color);

	if (!BoundaryCheck(y - 1, x) && !visited[y - 1][x] && picture[y - 1][x] == color)
		cnt += DFS(picture, y - 1, x, visited, color);

	if (!BoundaryCheck(y, x - 1) && !visited[y][x - 1] && picture[y][x - 1] == color)
		cnt += DFS(picture, y, x - 1, visited, color);

	if (!BoundaryCheck(y, x + 1) && !visited[y][x + 1] && picture[y][x + 1] == color)
		cnt += DFS(picture, y, x + 1, visited, color);

	return cnt;

}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	M = m;
	N = n;
	vector<int> answer(2, 0);
	vector<vector<bool>> visited(m, vector<bool>(n, false));


	int areaCnt = 0;
	int maxCnt = -INF;
	for (int i = 0; i < picture.size(); i++)
	{
		for (int j = 0; j < picture[i].size(); j++)
		{
			if (!visited[i][j] && picture[i][j] != 0)
			{
				areaCnt++;
				int cnt = DFS(picture, i, j, visited, picture[i][j]);
				maxCnt = max(maxCnt, cnt);
			}
		}
	}

	answer[0] = areaCnt;
	answer[1] = maxCnt;
	return answer;
}

int main()
{
	int m = 13;
	int n = 16;
	vector<vector<int>> picture = {
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
		{0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0},
		{0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0},
		{0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}
	};

	vector<int> ans = solution(m, n, picture);

	for (auto i : ans)
		cout << i << " ";
	cout << "\n";

	return 0;
}