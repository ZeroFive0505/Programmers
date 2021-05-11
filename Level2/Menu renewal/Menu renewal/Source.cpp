#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    map<int, int> maxSize;
    map<int, vector<string>> result;

    for (int i = 0; i < course.size(); i++)
    {
        maxSize[course[i]] = 1;
        vector<string> tmp;
        result[course[i]] = tmp;
    }

    for (int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    while (orders.size())
    {
        string order = orders[0];
        int order_size = order.size();
        orders.erase(orders.begin());
        vector<int> perm(order.size(), 0);

        for (int i = 0; i < course.size(); i++)
        {
            int size = course[i];
            if (order_size < size)
                continue;

            for (int j = order_size - 1; j >= order_size - size; j--)
                perm[j] = 1;

            do
            {
                string t;
                for (int j = 0; j < perm.size(); j++)
                {
                    if (perm[j] == 1)
                        t.push_back(order[j]);
                }

                int match = 1;

                for (int j = 0; j < orders.size(); j++)
                {
                    if (includes(orders[j].begin(), orders[j].end(), t.begin(), t.end()))
                        match++;
                }

                if (match == 1)
                    continue;

                if (match > maxSize[course[i]])
                {
                    maxSize[course[i]] = match;
                    result[course[i]].clear();
                    result[course[i]].push_back(t);
                }
                else if (match == maxSize[course[i]])
                {
                    result[course[i]].push_back(t);
                }

            } while (next_permutation(perm.begin(), perm.end()));
        }
    }


    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            answer.push_back(result[i][j]);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2, 3, 4 };

    vector<string> ans = solution(orders, course);

    for (auto s : ans)
        cout << s << " ";
    cout << "\n";

    return 0;
}