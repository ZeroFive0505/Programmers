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
        cache[i] = (cache[i - 1] + cache[i - 2]) % MOD;

    answer = cache[n];
    return answer;
}

int main()
{
    int n = 3;
    cout << solution(n) << "\n";
    return 0;
}