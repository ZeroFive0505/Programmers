#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string solution(string new_id)
{
	string answer = "";

	for (int i = 0; i < new_id.length(); i++)
	{
		if (isupper(new_id[i]))
			new_id[i] = tolower(new_id[i]);
	}

	new_id.erase(remove_if(new_id.begin(), new_id.end(), 
		[](unsigned char c) {return !isalnum(c) && c != '-' && c != '_' && c != '.'; }), new_id.end());

	if (new_id.length() > 1)
	{
		for (int i = 0; i < new_id.length() - 1;)
		{
			if (new_id[i] == '.' && new_id[i + 1] == '.')
			{
				int j;
				for (j = i; j < new_id.length(); j++)
					new_id[j] = new_id[j + 1];
			}
			else
				i++;
		}
	}

	new_id.erase(remove_if(new_id.begin(), new_id.end(), [](unsigned char c) {return c == '\0'; }), new_id.end());

	char c = new_id[0];

	if (c == '.')
		new_id.erase(new_id.begin());
	if (new_id.length() >= 2)
	{
		c = new_id[new_id.length() - 1];
		if (c == '.')
			new_id.pop_back();
	}

	if (new_id.empty())
		new_id = "a";
	else if (new_id.length() >= 16)
	{
		new_id.erase(new_id.begin() + 15, new_id.end());
		if (new_id.length() > 2)
		{
			c = new_id[new_id.length() - 1];
			if (c == '.')
				new_id.pop_back();
		}
	}

	if (new_id.length() <= 2)
	{
		c = new_id[new_id.length() - 1];
		while (new_id.length() != 3)
			new_id += c;
	}
	

	answer = new_id;
	return answer;
}

int main()
{
	string new_id = ".1.";
	cout << solution(new_id) << "\n";

	return 0;
}