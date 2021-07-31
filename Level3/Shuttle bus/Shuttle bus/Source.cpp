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

    int busTime = 0;

    for (int i = 0; i < n; i++)
    {
        int capacity = m;

        for (int j = idx; j < times.size(); j++)
        {
            if (times[j] <= start)
            {
                capacity--;
                idx++;

                if (capacity == 0)
                    break;
            }
        }

        if (i == n - 1)
        {
            if (capacity == 0)
                busTime = times[idx - 1] - 1;
            else
                busTime = start;
        }

        start += t;

        if (start >= (60 * 24))
            break;
    }

    
    int hour = busTime / 60;

    if (hour < 10)
        answer += "0" + to_string(hour) + ":";
    else
        answer += to_string(hour) + ":";

    int minutes = busTime % 60;

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