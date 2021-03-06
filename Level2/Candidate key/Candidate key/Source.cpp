#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool IsMinimum(vector<int>& candidates, int key)
{
	for (int i = 0; i < candidates.size(); i++)
	{
		if ((candidates[i] & key) == candidates[i])
			return false;
	}

	return true;
}

int solution(vector<vector<string>> relation)
{
	int answer = 0;
	int rowSize = relation.size();
	int colSize = relation[0].size();
	vector<int> candidates;
	int combinations = 1 << colSize;

	for (int i = 1; i < combinations; i++)
	{
		set<string> s;
		for (int j = 0; j < rowSize; j++)
		{
			unsigned int mask = 1;
			string key;
			for (int k = 0; k < colSize; k++, mask <<= 1)
			{
				if (i & mask)
				{
					key += relation[j][k];
				}
			}
			s.insert(key);
		}

		if (IsMinimum(candidates, i) && s.size() == rowSize)
			candidates.push_back(i);
	}
	answer = candidates.size();
	return answer;
}

int main()
{

	vector<vector<string>> r = {
		{"100", "ryan", "music", "2"},	
		{"200", "apeach", "math", "2"},
		{"300", "tube", "computer", "3"},
		{"400", "con", "computer", "4" },
		{"500", "muzi", "music", "3"},
		{"600", "apeach", "music", "2"}
	};

	cout << solution(r) << "\n";

	return 0;
}