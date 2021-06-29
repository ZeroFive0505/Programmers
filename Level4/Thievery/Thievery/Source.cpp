#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 1000000;

int cache[SIZE];

int solution(vector<int> money) 
{
    int answer = 0;

    if (money.size() == 1)
        return money[0];

    cache[0] = money[0];
    cache[1] = cache[0];

    for (int i = 2; i < money.size() - 1; i++)
    {
        cache[i] = max(cache[i - 2] + money[i], cache[i - 1]);
    }

    answer = max(answer, cache[money.size() - 2]);

    cache[0] = 0;
    cache[1] = money[1];

    for (int i = 2; i < money.size(); i++)
    {
        cache[i] = max(cache[i - 2] + money[i], cache[i - 1]);
    }

    answer = max(answer, cache[money.size() - 1]);

    return answer;
}

int main()
{

    vector<int> money = { 1, 2, 3, 1 };

    cout << solution(money) << "\n";

    return 0;
}