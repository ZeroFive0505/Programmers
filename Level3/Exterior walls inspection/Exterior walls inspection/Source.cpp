#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;

int solution(int n, vector<int> weak, vector<int> dist) 
{
    int answer = INF;

    vector<int> temp(weak.size() * 2, 0);

    for (int i = 0; i < temp.size(); i++)
    {
        if (i < weak.size())
            temp[i] = weak[i];
        else
            temp[i] = weak[i - weak.size()] + n;
    }

    sort(dist.begin(), dist.end());


    do
    {
        for (int i = 0; i < weak.size(); i++)
        {
            int start = temp[i];
            int end = temp[weak.size() + i - 1];

            for (int j = 0; j < dist.size(); j++)
            {
                start += dist[j];

                if (start >= end)
                {
                    answer = min(answer, j + 1);
                    break;
                }

                int nextPoint = upper_bound(temp.begin(), temp.end(), start) - temp.begin();
                start = temp[nextPoint];
            }
        }

    } while (next_permutation(dist.begin(), dist.end()));

    return answer;
}

int main()
{
    int n = 12;
    vector<int> weak = { 1, 3, 4, 9, 10 };
    vector<int> dist = { 3, 5, 7 };

    cout << solution(n, weak, dist) << "\n";

    return 0;
}