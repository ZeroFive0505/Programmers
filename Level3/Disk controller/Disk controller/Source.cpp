#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> jobs)
{
	int answer = 0;

	sort(jobs.begin(), jobs.end());

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int idx = 0;
	int elapsedTime = 0;

	while (idx < jobs.size() || !pq.empty())
	{
		if (idx < jobs.size() && elapsedTime >= jobs[idx][0])
		{
			pq.push({ jobs[idx][1], jobs[idx][0] });
			idx++;
			continue;
		}

		if (!pq.empty())
		{
			elapsedTime += pq.top().first;
			answer += elapsedTime - pq.top().second;
			pq.pop();
		}
		else
			elapsedTime = jobs[idx][0];
	}

	return answer / jobs.size();
}

int main()
{
	vector<vector<int>> jobs = {
		{0, 3},
		{1, 9},
		{2, 6}
	};

	cout << solution(jobs) << "\n";

	return 0;
}