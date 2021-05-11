#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) 
{
    bool answer = true;
    vector<int> digits;
    int t = x;
    while (t)
    {
        int r = t % 10;
        digits.push_back(r);
        t /= 10;
    }

    int sum = 0;
    for (auto i : digits)
        sum += i;

    if ((x % sum) != 0)
        answer = false;

    return answer;
}

int main()
{
    int x;
    while (1)
    {
        cin >> x;
        cout << solution(x) << "\n";
    }

    return 0;
}