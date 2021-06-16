#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int cache[100001];

int solution(int n, vector<int> money) 
{
    int answer = 0;
    cache[0] = 1;

    for (int i = money[0]; i <= n; i += money[0])
        cache[i] = 1;

    for (int i = 1; i < money.size(); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j >= money[i])
                cache[j] += cache[j - money[i]] % MOD;
        }
    }
    answer = cache[n];
    return answer;
}

int main()
{
    int n = 5;
    vector<int> money = { 1, 2, 5 };
    cout << solution(n, money) << "\n";
    return 0;
}