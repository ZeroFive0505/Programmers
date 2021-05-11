#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
	int size = s.length();
	int pCount = 0;
	int yCount = 0;
	for (int i = 0; i < size; i++)
	{
		if (s[i] == 'p' || s[i] == 'P')
			pCount++;
		else if (s[i] == 'y' || s[i] == 'Y')
			yCount++;
	}


	if (pCount == yCount)
		answer = true;
	else
		answer = false;
    return answer;
}

int main()
{
	string s;
	while (1)
	{
		cin >> s;
		cout << solution(s) << "\n";
	}

	return 0;
}