#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;

    sort(citations.begin(), citations.end(), [](const int a, const int b) {
        return a > b;
    });

    for (int i = 0; i < citations.size(); i++)
    {
        if ((i + 1) <= citations[i])
            answer++;
    }

    return answer;
}

int main()
{
    vector<int> c = { 22, 42 };

    cout << solution(c) << "\n";

    return 0;
}