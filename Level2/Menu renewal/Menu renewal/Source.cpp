#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    map<int, int> maxCourseSize;
    map<int, vector<string>> maxResult;

    for (int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
    }

    for (int i = 0; i < course.size(); i++)
    {
        maxCourseSize[course[i]] = 1;
        vector<string> v;
        maxResult[course[i]] = v;
    }

    while (orders.size())
    {
        string order = orders.front();
        int orderSize = order.size();
        vector<int> perm(orderSize, 0);
        orders.erase(orders.begin());

        for (int i = 0; i < course.size(); i++)
        {
            if (orderSize < course[i])
                continue;

            for (int j = orderSize - 1; j >= orderSize - course[i]; j--)
                perm[j] = 1;

            do
            {
                string courseComb;

                for (int j = 0; j < perm.size(); j++)
                {
                    if (perm[j] == 1)
                        courseComb.push_back(order[j]);
                }

                int match = 1;

                for (int j = 0; j < orders.size(); j++)
                {
                    if (includes(orders[j].begin(), orders[j].end(), courseComb.begin(), courseComb.end()))
                        match++;
                }

                if (match == 1)
                    continue;

                if (match > maxCourseSize[course[i]])
                {
                    maxCourseSize[course[i]] = match;
                    maxResult[course[i]].clear();
                    maxResult[course[i]].push_back(courseComb);
                }
                else if (match == maxCourseSize[course[i]])
                {
                    maxResult[course[i]].push_back(courseComb);
                }

            } while (next_permutation(perm.begin(), perm.end()));
        }
    }

    for (int i = 0; i < maxResult.size(); i++)
    {
        for (int j = 0; j < maxResult[i].size(); j++)
        {
            answer.push_back(maxResult[i][j]);
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