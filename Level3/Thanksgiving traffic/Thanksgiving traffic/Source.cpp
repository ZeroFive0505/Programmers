#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) 
{
    int answer = 0;
    vector<int> start;
    vector<int> end;
    for (int i = 0; i < lines.size(); i++)
    {
        string hour, minute, seconds, miliSec;

        int h, m, s;

        lines[i].pop_back();

        hour = lines[i].substr(11, 2);
        minute = lines[i].substr(14, 2);
        seconds = lines[i].substr(17, 2);
        miliSec = lines[i].substr(20, 3);

        int duration = stof(lines[i].substr(24, 5)) * 1000;

        h = stoi(hour) * 3600 * 1000;
        m = stoi(minute) * 60 * 1000;
        s = stoi(seconds) * 1000 + stoi(miliSec);

        start.push_back(h + m + s - duration + 1);
        end.push_back(h + m + s);
    }

    for (int i = 0; i < lines.size(); i++)
    {
        int endTime = end[i] + 1000;

        int cnt = 0;

        for (int j = i; j < lines.size(); j++)
        {
            if (start[j] < endTime)
                cnt++;
        }

        if (answer < cnt)
            answer = cnt;
    }

    return answer;
}

int main()
{

    vector<string> lines = {
        "2016-09-15 01:00:04.002 2.0s",
        "2016-09-15 01:00:07.000 2s"
    };

    cout << solution(lines) << "\n";

    return 0;
}