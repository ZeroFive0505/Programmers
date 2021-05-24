#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int DIV = 1000000007;

const int SIZE = 60001;

int cache[SIZE];

int tiling(int n)
{
    if (n <= 1)
        return 1;
    int& ret = cache[n];

    if (ret != -1)
        return ret;

    return ret = (tiling(n - 1) + tiling(n - 2)) % DIV;
}

int solution(int n) 
{
    int answer = 0;

    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    answer = tiling(n);

    return answer;
}

int main()
{
    cout << solution(4) << "\n";

    return 0;
}