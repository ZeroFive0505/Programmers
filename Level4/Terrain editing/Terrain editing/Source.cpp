#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long Calc(vector<vector<int>>& land, long long height, int P, int Q)
{
	long long ret = 0;

	for (int i = 0; i < land.size(); i++)
	{
		for (int j = 0; j < land[i].size(); j++)
		{
			long long diff = height - land[i][j];

			if (diff > 0)
				ret += (long long)diff * P;
			else if (diff < 0)
				ret += (long long)abs(diff) * Q;
		}
	}

	return ret;
}

long long solution(vector<vector<int>> land, int P, int Q)
{
	long long answer = 0;

	long long minH = land[0][0];
	long long maxH = land[0][0];
	for (int i = 0; i < land.size(); i++)
	{
		for (int j = 0; j < land[i].size(); j++)
		{
			maxH = max(maxH, (long long)land[i][j]);
			minH = min(minH, (long long)land[i][j]);
		}
	}

	long long mid = 0;

	while (minH <= maxH)
	{
		mid = (minH + maxH) / 2;

		if (minH == maxH)
			break;

		long long result1 = Calc(land, mid, P, Q);
		long long result2 = Calc(land, mid + 1, P, Q);

		if (result1 == result2)
			break;
		else if (result1 < result2)
			maxH = mid;
		else
			minH = mid + 1;
	}

	return Calc(land, mid, P, Q);
}

int main()
{
	vector<vector<int>> land = {
		{4, 4, 3},
		{3, 2, 2},
		{2, 1, 0}
	};

	int P = 5; // Add

	int Q = 3; // Remove

	cout << solution(land, P, Q);
	
	return 0;
}