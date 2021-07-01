#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

const int SIZE = 5001;

long long cache[SIZE];

int solution(int n)
{
    int answer = 0;
    memset(cache, -1, sizeof(cache));
    cache[0] = 1;
    cache[2] = 3;

    for (int i = 4; i <= n; i += 2)
    {
        cache[i] = cache[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2)
        {
            cache[i] = cache[i] + cache[j] * 2;
        }

        cache[i] = cache[i] % MOD;
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