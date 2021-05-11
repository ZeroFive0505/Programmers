#include <iostream>
#include <set>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

bool boundaryCheck(int y, int x, int m, int n)
{
	if (y >= m || x >= n)
		return true;
	else if (y < 0 || x < 0)
		return true;
	else
		return false;
}

int DFS(int y, int x, int m, int n, int colorCode, vector<vector<int>>& picture, vector<vector<bool>>& visited)
{
	int cnt = 1;
	visited[y][x] = true;
	if (!boundaryCheck(y + 1, x, m, n) && colorCode == picture[y + 1][x] && !visited[y + 1][x])
		cnt += DFS(y + 1, x, m, n, colorCode, picture, visited);
	if (!boundaryCheck(y - 1, x, m, n) && colorCode == picture[y - 1][x] && !visited[y - 1][x])
		cnt += DFS(y - 1, x, m, n, colorCode, picture, visited);
	if (!boundaryCheck(y, x + 1, m, n) && colorCode == picture[y][x + 1] && !visited[y][x + 1])
		cnt += DFS(y, x + 1, m, n, colorCode, picture, visited);
	if (!boundaryCheck(y, x - 1, m, n) && colorCode == picture[y][x - 1] && !visited[y][x - 1])
		cnt += DFS(y, x - 1, m, n, colorCode, picture, visited);

	return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<vector<bool>> visited(m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			visited[i].push_back(false);
	}

	int maxCnt = INT_MIN;
	int areaCnt = 0;

	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (picture[y][x] != 0 && !visited[y][x])
			{
				int temp = DFS(y, x, m, n, picture[y][x], picture, visited);
				maxCnt = max(temp, maxCnt);
				areaCnt++;
			}
		}
	}

	number_of_area = areaCnt;
	max_size_of_one_area = maxCnt;
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
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