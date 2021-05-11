#include <iostream>
#include <string>

using namespace std;

string solution(int n) 
{
	string answer = "";
	const char* p[] = { "¼ö", "¹Ú" };

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			answer += p[0];
		else
			answer += p[1];
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