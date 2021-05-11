#include <iostream>
#include <string>
#include <vector>

using namespace std;

string days_of_the_week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int days[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string solution(int a, int b)
{
	int startDay = 5;
	string answer = "";
	for (int i = 0; i < (a - 1); i++)
		startDay += days[i];
	startDay += (b - 1);
	answer = days_of_the_week[(startDay % 7)];
	

	return answer;
}

int main()
{
	int m, d;
	while (1)
	{
		cin >> m >> d;
		if (m == 0 || d == 0)
			break;
		cout << solution(m, d) << "\n";
	}

	return 0;
}