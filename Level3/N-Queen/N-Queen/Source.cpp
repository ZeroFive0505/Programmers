#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 13;

bool Check1[SIZE];
bool Check2[SIZE * 2];
bool Check3[SIZE * 2];
int N;
int answer = 0;


void Place(int i)
{
	int j;


	for (j = 0; j < N; j++)
	{
		if (!Check1[j] && !Check2[i + j] && !Check3[i - j + (N - 1)])
		{
			if (i == N - 1)
				answer++;
			else
			{
				Check1[j] = Check2[i + j] = Check3[i - j + (N - 1)] = true;
				Place(i + 1);
				Check1[j] = Check2[i + j] = Check3[i - j + (N - 1)] = false;
			}
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