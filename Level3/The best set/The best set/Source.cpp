#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) 
{
    vector<int> answer;

    if (n > s)
        return vector<int>{-1};

    int num = s / n;

    for (int i = 0; i < n; i++)
        answer.push_back(num);

    int remainder = s % n;

    for (int i = 0; i < remainder; i++)
        answer[i]++;

    sort(answer.begin(), answer.end());

	return answer;
}

int main()
{
    int n = 2;
    int s = 9;

    vector<int> ans = solution(n, s);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}