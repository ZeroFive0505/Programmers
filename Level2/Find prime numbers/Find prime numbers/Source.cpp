#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool IsPrime(int num)
{
    if (num < 2)
        return false;

    if (num == 2)
        return true;

    int n = sqrt(num);
    
    for (int i = 2; i <= n; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int solution(string numbers) 
{
    int answer = 0;
    vector<int> perm;

    for (int i = 0; i < numbers.size(); i++)
        perm.push_back(i);

    vector<string> v;

    do
    {
        string t;
        for (int i = 0; i < numbers.size(); i++)
        {
            t += numbers[perm[i]];
            v.push_back(t);
        }


    } while (next_permutation(perm.begin(), perm.end()));

    set<int> s;

    for (int i = 0; i < v.size(); i++)
    {
        int n = stoi(v[i]);
        if (IsPrime(stoi(v[i])) && s.count(n) == 0)
        {
            answer++;
            s.insert(n);
        }
    }

    return answer;
}

int main()
{
    string numbers = "011";

    cout << solution(numbers) << "\n";

    return 0;
}