#include <iostream>

using namespace std;
const int SIZE = 2001;
const int MOD = 1234567;

long long cache[SIZE];

long long solution(int n) 
{
    long long answer = 0;
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        cache[i] = (cache[i - 2] + cache[i - 1]) % MOD;
    }

    answer = cache[n];
    return answer;
}

int main()
{
    int n = 4;
    cout << solution(n) << "\n";
    return 0;
}