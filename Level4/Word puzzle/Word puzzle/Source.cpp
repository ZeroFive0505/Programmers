#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 20001;
int cache[SIZE];

int solution(vector<string> strs, string t)
{
    int answer = 0;
    int i, j, p, q;

    fill(cache, cache + SIZE, 0);

    for (i = 0; i < t.size(); i++)
    {
        cache[i] = t.size() + 1;

        for (j = 0; j < strs.size(); j++)
        {
            p = strs[j].size() - 1;

            for (q = 0; q < strs[j].size(); q++)
            {
                if (!(p - q < 0 || i - q < 0) && strs[j][p - q] == t[i - q])
                    continue;
                else
                    break;
            }

            if (q == strs[j].size())
            {
                if (i - q >= 0)
                    cache[i] = min(cache[i], 1 + cache[i - q]);
                else
                    cache[i] = 1;
            }
        }
    }
    
    answer = cache[t.size() - 1];

    if (answer == t.size() + 1)
        answer = -1;

    return answer;
}

int main()
{
    vector<string> strs = { "app","ap","p","l","e","ple","pp" };
    string t = "apple";

    cout << solution(strs, t) << "\n";

    return 0;
}