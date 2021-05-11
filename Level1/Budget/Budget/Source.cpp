#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) 
{
    int answer = 0;
    vector<int> prefixSum;
    sort(d.begin(), d.end());

    prefixSum.push_back(d[0]);
    for (int i = 1; i < d.size(); i++)
    {
        prefixSum.push_back(prefixSum[i - 1] + d[i]);
    }

    for (auto i : prefixSum)
    {
        if (i <= budget)
            answer++;
    }

    return answer;
}

int main()
{
    vector<int> d = { 2, 2, 3, 3 };
    int budget = 10;
    cout << solution(d, budget);
    return 0;
}