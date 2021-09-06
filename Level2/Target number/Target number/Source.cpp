#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int N;
void DFS(int depth, vector<int>& numbers, int sum, int target)
{
	if (depth == N)
	{
		if(sum == target)	
			cnt++;
		return;
	}

	DFS(depth + 1, numbers, sum + numbers[depth], target);
	DFS(depth + 1, numbers, sum - numbers[depth], target);
}

int solution(vector<int> numbers, int target)
{
	int answer = 0;
	N = numbers.size();
	DFS(0, numbers, 0, target);
	answer = cnt;
	return answer;
}

int main()
{
	vector<int> n = { 1, 1, 1, 1, 1 };
	int target = 3;

	cout << solution(n, target) << "\n";

	return 0;
}