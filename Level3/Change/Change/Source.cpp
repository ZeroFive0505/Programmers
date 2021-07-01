#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n, vector<int> money) 
{
    int answer = 0;
    vector<int> cache(n + 1, 0);

    cache[0] = 1;

    for (int m : money)
    {
        for (int i = m; i <= n; i++)
        {
            cache[i] += cache[i - m];
            cache[i] %= MOD;
        }
    }

    return answer;
}

int main()
{
    int n = 5;
    vector<int> money = { 1, 2, 5 };
    cout << solution(n, money) << "\n";
    return 0;
}