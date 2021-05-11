#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1000001;

bool IsPrime[1000001];

int solution(int n)
{
	int answer = 0;

	fill(IsPrime, IsPrime + SIZE, true);
	IsPrime[0] = IsPrime[1] = false;

	for (int i = 2; i < SIZE / 2; i++)
	{
		int j = 2;
		while (1)
		{
			int mul = i * j;
			if (mul >= SIZE)
				break;
			IsPrime[mul] = false;
			j++;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (IsPrime[i])
			answer++;
	}

	return answer;
}

int main()
{
	int n;
	while (1)
	{
		cin >> n;
		cout << solution(n) << "\n";
	}
	return 0;
}