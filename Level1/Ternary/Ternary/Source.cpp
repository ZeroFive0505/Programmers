#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(int n)
{
	int answer = 0;
	vector<int> v;
	int deg = 0;
	while (n)
	{
		v.push_back(n % 3);
		n /= 3;
	}

	vector<int>::reverse_iterator it;
	int sum = 0;
	for (it = v.rbegin(); it != v.rend(); it++)
	{
		sum += *it * (int)pow(3, deg++);
	}

	answer = sum;
	return answer;
}

int main()
{
	int n;

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		cout << solution(n) << "\n";
	}

	return 0;
}