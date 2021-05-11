#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) 
{
    vector<long long> answer;
    
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            answer.push_back(x);
        else
        {
            long long t = answer.back();
            answer.push_back(t + x);
        }
    }


    return answer;
}

int main()
{
    int x;
    int n;
    vector<long long> s;
    while (1)
    {
        cin >> x >> n;
        s = solution(x, n);
        for (auto i : s)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}