#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int n, int m)
{
    while (m)
    {
        int z = n;
        n = m;
        m = z % m;
    }

    return n;
}

vector<int> solution(int n, int m) 
{
    vector<int> answer;

    int gcd = GCD(n, m);
    int lcm = (n * m) / gcd;
    
    answer.push_back(gcd);
    answer.push_back(lcm);

    return answer;
}

int main()
{
    while (1)
    {
        int n, m;
        cin >> n >> m;
        vector<int> s = solution(n, m);
        for (auto i : s)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}