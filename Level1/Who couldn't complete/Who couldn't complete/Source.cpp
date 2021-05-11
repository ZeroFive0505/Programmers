#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";
	map<string, int> m;

	vector<string>::iterator it;
	for (it = participant.begin(); it != participant.end(); it++)
		m[*it]++;

	for (it = completion.begin(); it != completion.end(); it++)
		m[*it]--;

	map<string, int>::iterator mit;

	for (mit = m.begin(); mit != m.end(); mit++)
	{
		if ((*mit).second == 1)
		{
			answer = (*mit).first;
			break;
		}
	}

	return answer;
}

int main()
{
	vector<string> p = { "leo", "kiki", "eden" };
	vector<string> c = { "eden", "kiki" };
	cout << solution(p, c) << "\n";
	return 0;
}