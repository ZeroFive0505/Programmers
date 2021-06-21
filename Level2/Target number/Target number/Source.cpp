#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

void DFS(vector<int>& numbers, int sum, int currentSize, int target)
{
	if (currentSize == numbers.size())
	{
		if(sum == target)
			cnt++;

		return;
	}

	DFS(numbers, sum + numbers[currentSize], currentSize + 1, target);
	DFS(numbers, sum - numbers[currentSize], currentSize + 1, target);
}


int solution(vector<int> numbers, int target)
{
	int answer = 0;

	DFS(numbers, 0, 0, target);
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