#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int arr[110][110];

int Place2(int n, int gap)
{
    int res = 0;
    while (1)
    {
        int x, y;

        bool flag = true;

        for (int j = 0; flag && j < n; j++)
        {
            for (int i = 0; flag && i < n; i++)
            {
                if (arr[i][j] == 0)
                {
                    res++;
                    x = i;
                    y = j;
                    flag = false;
                    break;
                }
            }  
        }

        if (!flag)
        {
            arr[x][y] = 2;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr[i][j] == 0 && abs(i - x) + abs(j - y) <= gap)
                        arr[i][j] = 1;
                }
            }
        }
        else
            break;
    }

    return res;
}

int Place(int n, int gap)
{
    int ret = 0;

    for (int i = 0; i < n; i++)
    {
        memset(arr, 0, sizeof(arr));
        arr[0][i] = 2;

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (abs(j) + abs(k - i) <= gap)
                    arr[j][k] = 1;
            }
        }

        ret = max(ret, Place2(n, gap) + 1);
    }

    return ret;
}


int solution(int n, int m, vector<vector<int>> timetable) 
{
    int answer = 0;

    vector<int> mark(1321, 0);

    for (auto i : timetable)
    {
        mark[i[0]]++;
        mark[i[1] + 1]--;
    }

    int with = 0, now = 0;

    for (int i = 0; i < mark.size(); i++)
    {
        now += mark[i];
        with = max(with, now);
    }

    if (with <= 1)
        return 0;

    vector<int> gap(30);

    for (int i = 0; i < 30; i++)
        gap[i] = Place(n, i);

    
    while (gap[answer] >= with)
        answer++;

    return answer;
}

int main()
{
    int n = 2;
    int m = 2;

    vector<vector<int>> timetable = {
        {600, 630},
        {630, 700}
    };

    cout << solution(n, m, timetable) << "\n";

    return 0;
}