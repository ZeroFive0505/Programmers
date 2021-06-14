#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string Converter(string melody, map<string, string>& conv)
{
    string m;
    for (int i = 0; i < melody.size(); i++)
    {
        if (melody[i + 1] == '#')
        {
            string temp;
            temp.push_back(melody[i]);
            temp.push_back(melody[i + 1]);
            m += conv[temp];
            i++;
        }
        else
            m += melody[i];
    }

    return m;
}

string solution(string m, vector<string> musicinfos) 
{
    string answer = "(None)";
    int startTime;
    int endTime;
    int maxTime = 0;

    map<string, string> conv;

    conv["C#"] = "1";
    conv["D#"] = "2";
    conv["F#"] = "3";
    conv["G#"] = "4";
    conv["A#"] = "5";

    string melody = Converter(m, conv);

    for (int i = 0; i < musicinfos.size(); i++)
    {
        string startHour = musicinfos[i].substr(0, 2);
        string startMin = musicinfos[i].substr(3, 2);

        string endHour = musicinfos[i].substr(6, 2);
        string endMin = musicinfos[i].substr(9, 2);

        string song;
        string music;

        for (int j = 12; j < musicinfos[i].size(); j++)
        {
            if (musicinfos[i][j] == ',')
            {
                song = musicinfos[i].substr(12, j - 12);
                music = musicinfos[i].substr(j + 1);
                break;
            }
        }

        startTime = stoi(startHour) * 60 + stoi(startMin);
        endTime = stoi(endHour) * 60 + stoi(endMin);

        int duration = endTime - startTime;

        string tmp = Converter(music, conv);

        if (duration > tmp.size())
        {
            music = tmp;

            for (int j = 1; j < duration / tmp.size(); j++)
                music += tmp;
            for (int j = 0; j < duration % tmp.size(); j++)
                music += tmp[j];
        }
        else
            music = tmp.substr(0, duration);

        if (music.find(melody) != string::npos)
        {
            if (maxTime < duration)
            {
                maxTime = duration;
                answer = song;
            }
        }
    }

    return answer;
}

int main()
{
    string m = "ABCDEFG";
    vector<string> musicinfos = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };

    cout << solution(m, musicinfos) << "\n";

    return 0;
}