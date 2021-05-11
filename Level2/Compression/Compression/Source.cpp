#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

char GetAlpha(int code)
{
    return char(code);
}

vector<int> solution(string msg) 
{
    vector<int> answer;
    map<string, int> dict;
    int idx = 1;
    for (int i = 0; i < 26; i++)
        dict[string(1, GetAlpha('A' + i))] = idx++;

    int size = msg.size();

    for (int i = 0; i < size;)
    {
        string key(1, msg[i]);
        if (dict.count(key) != 0)
        {
            string temp = key;
            string last;
            int j = i + 1;
            bool found = false;
            while (j < size)
            {
                key += msg[j++];
                if (dict.count(key) == 0)
                {
                    dict[key] = idx++;
                    break;
                }
                else
                    found = true;

                last = key;
            }

            if (!found)
            {
                answer.push_back(dict[temp]);
                i++;
            }
            else
            {
                answer.push_back(dict[last]);
                i += last.length();
            }
        }
    }

    return answer;
}

int main()
{
    string msg = "ABABABABABABABAB";
    vector<int> ans = solution(msg);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}