#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(long long n) 
{
    long long answer = 0;

    long long r;
    
    vector<long long> v;

    while (n)
    {
        r = n % 10;
        v.push_back(r);
        n /= 10;
    }

    sort(v.begin(), v.end(), [](const long long a, const long long b) {
        return a < b;
    });

    long long deg = 1;
    for (auto i : v)
    {
        answer += i * deg;
        deg *= 10;
    }

    return answer;
}

int main()
{
    long long n;
    while (1)
    {
        cin >> n;
        cout << solution(n) << "\n";
    }

    return 0;
}