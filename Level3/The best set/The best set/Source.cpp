#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) 
{
    vector<int> answer;


    if (s / n == 0)
        return vector<int>{-1};

    int quotient = s / n;
    int remainder = s % n;

    vector<int> temp;

    for (int i = 0; i < n; i++)
        temp.push_back(quotient);

    for (int i = 0; i < remainder; i++)
        temp[i]++;

    sort(temp.begin(), temp.end());


	answer = temp;
	return answer;

}

int main()
{
    int n = 2;
    int s = 8;

    vector<int> ans = solution(n, s);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}