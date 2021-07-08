#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int solution(int n) 
{
    int answer = 0;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back(1);
        v.push_back(-1);
    }

    do
    {
        int sum = 0;
        bool match = true;
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];

            if (sum < 0)
            {
                match = false;
                break;
            }
        }

        if (match)
            answer++;

    } while (next_permutation(v.begin(), v.end()));

    return answer;
}

int main()
{
    int n = 3;

    cout << solution(n) << "\n";

    return 0;
}