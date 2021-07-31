#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int GetN_Number(int n, int power)
{
    int ret = 0;
    while (power)
    {
        power--;
        ret = ret + n * pow(10, power);
    }

    return ret;
}

int solution(int N, int number) 
{
    if (N == number)
        return 1;

    int answer = -1;

    vector<set<int>> v(8);
    
    int cnt = 1;
    for (auto& i : v)
    {
        i.insert(GetN_Number(N, cnt++));
    }

    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (const auto& op1 : v[j])
            {
                for (const auto& op2 : v[i - j - 1])
                {
                    v[i].insert(op1 + op2);
                    v[i].insert(op1 - op2);
                    v[i].insert(op1 * op2);

                    if (op2 != 0)
                        v[i].insert(op1 / op2);
                }
            }
        }

        if (v[i].find(number) != v[i].end())
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}

int main()
{
    int N = 5;
    int number = 12;

    cout << solution(N, number) << "\n";

    return 0;
}