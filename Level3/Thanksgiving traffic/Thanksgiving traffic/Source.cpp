#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) 
{
    int answer = 0;
    vector<int> start;
    vector<int> end;

    for (int i = 0; i < lines.size(); i++)
    {
        string traffic = lines[i];
        traffic.pop_back();
        string hourStr, minuteStr, secStr, miliSecStr;
        int hour, minute, sec, miliSec;

        hourStr = traffic.substr(11, 12);
        minuteStr = traffic.substr(14, 15);
        secStr = traffic.substr(17, 18);
        miliSecStr = traffic.substr(20, 22);

        hour = stoi(hourStr) * 3600 * 1000;
        minute = stoi(minuteStr) * 60 * 1000;
        sec = stoi(secStr) * 1000;
        miliSec = stoi(miliSecStr);

        int taskTime = stof(traffic.substr(24, traffic.length())) * 1000;

        start.push_back(hour + minute + sec + miliSec - taskTime + 1);
        end.push_back(hour + minute + sec + miliSec);
    }

    for (int i = 0; i < lines.size(); i++)
    {
        int endTime = end[i] + 1000;
        int tmp = 0;
        for (int j = i; j < lines.size(); j++)
        {
            if (start[j] < endTime)
                tmp++;
        }

        answer = max(tmp, answer);
    }

    return answer;
}

int main()
{

    vector<string> lines = {
        "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.299 0.8s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
        "2016-09-15 21:00:02.066 2.62s"
    };

    cout << solution(lines) << "\n";

    return 0;
}