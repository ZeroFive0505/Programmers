#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer = 0;
	vector<int> v;
	unordered_map<string, vector<string>> m;
	for (int i = 0; i < clothes.size(); i++)
	{
		vector<string> s = clothes[i];
		m[s[1]].push_back(s[0]);
	}


	unordered_map<string, vector<string>>::const_iterator it;
	int mul = 1;
	for (it = m.begin(); it != m.end(); it++)
	{
		string cat = (*it).first;
		mul *= (m[cat].size() + 1);
	}
	
	answer = mul - 1;

	return answer;
}

int main()
{
	vector<vector<string>> c = {
		{"yellowhat", "headgear"},	
		{"bluesunglasses", "eyewear"},	
		{"green_turban", "headgear"}
	};

	cout << solution(c) << "\n";

	return 0;
}