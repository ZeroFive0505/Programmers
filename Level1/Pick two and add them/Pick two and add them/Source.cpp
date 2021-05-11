#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers)
{
	vector<int> answer;
	set<int> numberset;


	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			int sum = numbers[i] + numbers[j];
			numberset.insert(sum);
		}
	}

	set<int>::iterator it;

	for (it = numberset.begin(); it != numberset.end(); it++)
		answer.push_back(*it);

	return answer;
}


int main()
{

	vector<int> numbers{ 2,1,3,4,1 };
	vector<int> ans = solution(numbers);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}
