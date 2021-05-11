#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;
    stack<pair<int, int>> s;
    vector<pair<int, int>> v;
    int i;

    for (i = 0; i < prices.size(); i++)
        v.push_back({ prices[i], i });

    s.push(v[0]);

    while (s.size() != prices.size())
    {
        pair<int, int> t = s.top();
        int cnt = 0;
        for (i = t.second + 1; i < prices.size(); i++)
        {
            if (prices[i] >= t.first)
                cnt++;
            else
            {
                cnt++;
                break;
            }
        }

        answer.push_back(cnt);
        
        if (t.second + 1 < prices.size())
            s.push({ prices[t.second + 1], t.second + 1 });
    }

    answer.push_back(0);

    return answer;
}

int main()
{
    vector<int> prices = { 1, 2, 3, 2, 3, 1 };
    vector<int> s = solution(prices);
    for (auto i : s)
        cout << i << " ";
    cout << "\n";
    return 0;
}