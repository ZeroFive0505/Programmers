#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;



string solution(int n, int t, int m, vector<string> timetable) 
{
    string answer;

    vector<int> times;

    for (int i = 0; i < timetable.size(); i++)
    {
        string hour = timetable[i].substr(0, 2);
        string minutes = timetable[i].substr(3, 2);

        int total = stoi(hour) * 60 + stoi(minutes);

        times.push_back(total);
    }


    sort(times.begin(), times.end());


    int start = 540;

    int idx = 0;

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int capacity = m;
       
        for (int j = idx; j < times.size(); j++)
        {
            if (times[j] <= start)
            {
                idx++;
                capacity--;

                if (capacity == 0)
                    break;
            }
        }

        if (i + 1 == n)
        {
            if (capacity == 0)
                res = times[idx] - 1;
            else
                res = start;
        }

        start += t;
    }

    
    int hour = res / 60;

    if (hour < 10)
        answer += "0" + to_string(hour) + ":";
    else
        answer += to_string(hour) + ":";

    int minutes = res % 60;

    if (minutes < 10)
        answer += "0" + to_string(minutes);
    else
        answer += to_string(minutes);

    return answer;
}

int main()
{
    int n = 1;
    int t = 1;
    int m = 1;

    vector<string> timetable = {
        "23:59"
    };

    cout << solution(n, t, m, timetable) << "\n";

    return 0;
}