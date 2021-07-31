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
        string log = lines[i];

        string hourStr = log.substr(11, 2);
        string minStr = log.substr(14, 2);
        string secString = log.substr(17, 2);
        string miliSec = log.substr(20, 3);

        string durationStr = log.substr(24, 5);

        int hours = stoi(hourStr) * 3600 * 1000;
        int minutes = stoi(minStr) * 60 * 1000;
        int seconds = stoi(secString) * 1000 + stoi(miliSec);
        int duration = stof(durationStr) * 1000;

        start.push_back(hours + minutes + seconds - duration + 1);
        end.push_back(hours + minutes + seconds);
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

        answer = max(answer, cnt);
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