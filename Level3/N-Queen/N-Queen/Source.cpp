#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 13;
int answer = 0;
int N;

bool check[SIZE];
bool check1[SIZE * 2];
bool check2[SIZE * 2];

void Place(int i)
{
	if (i == N)
	{
		answer++;
		return;
	}

	for (int j = 0; j < N; j++)
	{
		if (!check[j] && !check1[i + j] && !check2[(N - 1) - (i - j)])
		{
			check[j] = check1[i + j] = check2[(N - 1) - (i - j)] = true;
			Place(i + 1);
			check[j] = check1[i + j] = check2[(N - 1) - (i - j)] = false;
		}
	}
}

int solution(int n)
{
	N = n;
	Place(0);
	return answer;
}

int main()
{
	int n = 4;

	cout << solution(4) << "\n";

	return 0;
}