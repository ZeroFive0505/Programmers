#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool IsPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(string numbers) 
{
    int answer = 0;
    vector<char> perm;
    vector<int> v;
    for (auto i : numbers)
    {
        perm.push_back(i);
        v.push_back(i - '0');
    }

    sort(perm.begin(), perm.end());

    do
    {
        string t = "";
        for (int i = 0; i < perm.size(); i++)
            t += perm[i];

        v.push_back(stoi(t));
    } while (next_permutation(perm.begin(), perm.end()));

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto i : v)
    {
        if (IsPrime(i))
            answer++;
    }

    return answer;
}

int main()
{
    string numbers = "011";

    cout << solution(numbers) << "\n";

    return 0;
}