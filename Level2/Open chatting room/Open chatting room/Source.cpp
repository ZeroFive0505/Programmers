#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;
    int size = record.size();
    map<int, string> logHash;
    //unordered_map<string, string> logHash;
    map<string, vector<int>> m;
    map<string, string> nameHash;
    int logNumber = 1;
    for (int i = 0; i < size; i++)
    {
        string s = record[i];
        size_t pos;
        pos = s.find(" ");
        string msg = s.substr(0, s.find(" "));
        s.erase(0, pos + 1);

        pos = s.find(" ");
        string uid = s.substr(0, s.find(" "));
        s.erase(0, pos + 1);

        string name = s.substr(0, s.find(" "));

        if (msg == "Enter")
        {
            if (m.count(uid) == 0)
                logHash[logNumber] = name + "님이 들어왔습니다.";
            else
            {
                if (name != nameHash[uid])
                {
                    vector<int> logs = m[uid];
                    for (int i = 0; i < logs.size(); i++)
                    {
                        string t = logHash[logs[i]];
                        string token = t.substr(nameHash[uid].length(), t.length());

                        t = name + token;

                        logHash[logs[i]] = t;
                    }
                }

                logHash[logNumber] = name + "님이 들어왔습니다.";
            }

            nameHash[uid] = name;
            m[uid].push_back(logNumber);
        }
        else if (msg == "Leave")
        {
            logHash[logNumber] = nameHash[uid] + "님이 나갔습니다.";

            m[uid].push_back(logNumber);
        }
        else
        {
            vector<int> logs = m[uid];
            for (int i = 0; i < logs.size(); i++)
            {
                string t = logHash[logs[i]];
                string token = t.substr(nameHash[uid].length(), t.length());

                t = name + token;

                logHash[logs[i]] = t;
            }

            nameHash[uid] = name;

        }

        logNumber++;
    }

    map<int, string>::const_iterator it;

    for (it = logHash.begin(); it != logHash.end(); it++)
    {
        answer.push_back((*it).second);
    }

    return answer;
}

int main()
{
    vector<string> r = {
        "Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan"
    };

    vector<string> ans = solution(r);

    for (auto i : ans)
        cout << i << "\n";

    return 0;
}