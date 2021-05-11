#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string Convert(string melody, map<string, char>& converter)
{
    string ret;
    for (int i = 0; i < melody.size(); i++)
    {
        if (melody[i + 1] == '#')
        {
            string key = melody.substr(i, 2);
            ret += converter[key];
            i++;
        }
        else
            ret += melody[i];
    }

    return ret;
}

string solution(string m, vector<string> musicinfos) 
{
    string answer = "(None)";
    int bHour = 0, bMin = 0, aHour = 0, aMin = 0, duration = 0, maxTime = 0;
    map<string, char> conv;

    conv["C#"] = '1';
    conv["D#"] = '2';
    conv["F#"] = '3';
    conv["G#"] = '4';
    conv["A#"] = '5';


    string melody = Convert(m, conv);
    string title;
    for (int i = 0; i < musicinfos.size(); i++)
    {
        string music;
        string tmp;
        bHour = stoi(musicinfos[i].substr(0, 2)) * 60;
        bMin = stoi(musicinfos[i].substr(3, 2));
        aHour = stoi(musicinfos[i].substr(6, 2)) * 60;
        aMin = stoi(musicinfos[i].substr(9, 2));


        duration = (aHour + aMin) - (bHour + bMin);

        
        for (int j = 12; j < musicinfos[i].size(); j++)
        {
            if (musicinfos[i][j] == ',')
            {
                title = musicinfos[i].substr(12, j - 12);
                tmp = musicinfos[i].substr(j + 1);
                break;
            }
        }

        music = Convert(tmp, conv);

        if (music.size() < duration)
        {
            tmp = music;

            for (int j = 1; j < duration / tmp.size(); j++)
                music += tmp;
            for (int j = 0; j < duration % tmp.size(); j++)
                music += tmp[j];
        }
        else
            music = music.substr(0, duration);

        if (music.find(melody) != string::npos)
        {
            if (maxTime < duration)
            {
                answer = title;
                maxTime = duration;
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