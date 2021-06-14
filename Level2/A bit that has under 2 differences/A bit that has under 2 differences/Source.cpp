#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) 
{
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        long long num = numbers[i];

        if (num % 2 == 0)
            num += 1;
        else
        {
            unsigned long long mask = 1;
            long long last = 0;
            for (int j = 0; j < 64; j++, mask <<= 1)
            {
                if (!(num & mask))
                {
                    num |= mask;
                    num ^= last;
                    break;
                }
                else
                    last = mask;
            }
        }
        answer.push_back(num);
    }

    return answer;
}

int main()
{
    vector<long long> numbers = { 2, 7 };

    vector<long long> ans = solution(numbers);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}