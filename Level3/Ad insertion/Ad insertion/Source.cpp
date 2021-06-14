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

    int iPlayTime = 0;
    int iAdvTime = 0;

    iPlayTime = stoi(play_time.substr(0, 2)) * 3600 + stoi(play_time.substr(3, 2)) * 60 + stoi(play_time.substr(6, 2));
    iAdvTime = stoi(adv_time.substr(0, 2)) * 3600 + stoi(adv_time.substr(3, 2)) * 60 + stoi(adv_time.substr(6, 2));

    if (iPlayTime == iAdvTime)
        return "00:00:00";

    vector<sLine> iLogs;
    int id = 1;
    for (int i = 0; i < logs.size(); i++)
    {
        string log = logs[i];

        int startHour = stoi(log.substr(0, 2)) * 3600;
        int startMin = stoi(log.substr(3, 2)) * 60;
        int startSec = stoi(log.substr(6, 2));

        int totalStart = startHour + startMin + startSec;

        int endHour = stoi(log.substr(9, 2)) * 3600;
        int endMin = stoi(log.substr(12, 2)) * 60;
        int endSec = stoi(log.substr(15, 2));

        int totalEnd = endHour + endMin + endSec;

        for (int i = totalStart; i < totalEnd; i++)
            AD[i]++;
    }

    int idx = 0;
    long long sum = 0;
    long long maxSum = 0;

    queue<int> q;

    for (int i = 0; i < iAdvTime; i++)
    {
        sum += AD[i];
        q.push(AD[i]);
    }

    maxSum = sum;

    for (int i = iAdvTime; i < iPlayTime; i++)
    {
        sum += AD[i];
        q.push(AD[i]);

        sum -= q.front();
        q.pop();

        if (sum > maxSum)
        {
            idx = i - iAdvTime + 1;
            maxSum = sum;
        }
    }

    int h = idx / 3600;

    if (h < 10)
        answer += "0" + to_string(h) + ":";
    else
        answer += to_string(h) + ":";
    idx %= 3600;

    int m = idx / 60;

    if (m < 10)
        answer += "0" + to_string(m) + ":";
    else
        answer += to_string(m) + ":";
    idx %= 60;

    int s = idx;

    if (s < 10)
        answer += "0" + to_string(s);
    else
        answer += to_string(s);

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
