#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) 
{
    vector<int> answer;
    long long r;
    while (n)
    {
        r = n % 10;
        answer.push_back(r);
        n /= 10;
    }

    return answer;
}

int main()
{
    long long n;
    vector<int> a;
    while (1)
    {
        cin >> n;
        a = solution(n);
        for (auto i : a)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}