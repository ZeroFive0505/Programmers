#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long Factorial[21] = { 1, };

vector<int> solution(int n, long long k) 
{
    vector<int> answer, number;

    long long current = 0;

    for (int i = 1; i <= n; i++)
    {
        Factorial[i] = Factorial[i - 1] * i;
        number.push_back(i);
    }

    k--;

    while (n > 0)
    {
        current = k / Factorial[n - 1];
        answer.push_back(number[current]);
        number.erase(number.begin() + current);
        k %= Factorial[n - 1];
        n--;
    }

    return answer;
}

int main()
{
    int n = 3;
    long long k = 5;

    vector<int> ans = solution(n, k);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    
    return 0;
}