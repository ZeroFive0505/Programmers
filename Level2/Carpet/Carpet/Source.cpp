#include <iostream>
#include <vector>

using namespace std;


vector<int> solution(int brown, int yellow)
{
	vector<int> answer;

	int sum = brown + yellow;

	for (int h = 3; ; h++)
	{
		if (sum % h == 0)
		{
			int w = sum / h;

			if ((w - 2) * (h - 2) == yellow)
			{
				answer.push_back(w);
				answer.push_back(h);
				break;
			}
		}
	}

	return answer;
}

int main()
{
	int brown = 24;
	int yellow = 24;

	vector<int> ans = solution(brown, yellow);

	for (auto i : ans)
		cout << i << " ";
	cout << "\n";

	return 0;
}