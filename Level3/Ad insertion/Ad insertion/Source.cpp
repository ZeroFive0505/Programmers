#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


int AD[360000];

struct sLine
{
    int start;
    int end;
    int id;
};

string solution(string play_time, string adv_time, vector<string> logs) 
{
    string answer = "";

    int playTime = stoi(play_time.substr(0, 2)) * 3600 + stoi(play_time.substr(3, 2)) * 60 + stoi(play_time.substr(6, 2));
    int advTime = stoi(adv_time.substr(0, 2)) * 3600 + stoi(adv_time.substr(3, 2)) * 60 + stoi(adv_time.substr(6, 2));

    if (playTime == advTime)
        return "00:00:00";

    for (int i = 0; i < logs.size(); i++)
    {
        int startHour = stoi(logs[i].substr(0, 2)) * 3600;
        int startMin = stoi(logs[i].substr(3, 2)) * 60;
        int startSec = stoi(logs[i].substr(6, 2));

        int endHour = stoi(logs[i].substr(9, 2)) * 3600;
        int endMin = stoi(logs[i].substr(12, 2)) * 60;
        int endSec = stoi(logs[i].substr(15, 2));

        int startTime = startHour + startMin + startSec;
        int endTime = endHour + endMin + endSec;

        for (int j = startTime; j < endTime; j++)
            AD[j]++;
    }

    int idx = 0;
    long long sum = 0;
    long long maxSum = 0;

    queue<int> q;

    for (int i = 0; i < advTime; i++)
    {
        sum += AD[i];
        q.push(AD[i]);
    }

    maxSum = sum;

    for (int i = advTime; i < playTime; i++)
    {
        sum += AD[i];
        q.push(AD[i]);

        sum -= q.front();
        q.pop();

        if (sum > maxSum)
        {
            idx = i - advTime + 1;
            maxSum = sum;
        }
    }

    int hour = idx / 3600;

    if (hour >= 10)
        answer += to_string(hour);
    else
        answer += "0" + to_string(hour);

    answer += ":";

    int minutes = idx % 3600 / 60;

    if (minutes >= 10)
        answer += to_string(minutes);
    else
        answer += "0" + to_string(minutes);

    answer += ":";

    int seconds = idx % 60;

    if (seconds >= 10)
        answer += to_string(seconds);
    else
        answer += "0" + to_string(seconds);
    
    
    return answer;
}

int main()
{
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs = {
        "01:20:15-01:45:14", 
        "00:40:31-01:00:00", 
        "00:25:50-00:48:29", 
        "01:30:59-01:53:29", 
        "01:37:44-02:02:30"
    };

    cout << solution(play_time, adv_time, logs) << "\n";

    return 0;
}
