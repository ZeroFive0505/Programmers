#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 10000000;

int Calc(int n)
{
    int num = sqrt(n);

    for (int i = 2; i <= num; i++)
    {
        if (n % i == 0 && n / i <= MAX)
            return n / i;
    }

    return 1;
}

vector<int> solution(long long begin, long long end) 
{
    vector<int> answer;

    for (long long i = begin; i <= end; i++)
        answer.push_back(Calc(i));

    if (begin == 1)
        answer[0] = 0;

    return answer;
}

int main()
{
    long long begin = 1;
    long long end = 10;

    vector<int> ans = solution(begin, end);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}