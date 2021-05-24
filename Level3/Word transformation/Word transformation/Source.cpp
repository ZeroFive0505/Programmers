#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool CanTransform(string a, string b)
{
    int cnt = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            cnt++;
    }

    if (cnt == 1)
        return true;
    else
        return false;
}

int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
    queue<pair<string, int>> q;

    string temp;
    int num;

    vector<bool> visited(begin.size(), false);

    q.push({ begin, 0 });

    while (!q.empty())
    {
        temp = q.front().first;
        num = q.front().second;
        q.pop();

        if (temp == target)
        {
            answer = num;
            break;
        }

        for (int i = 0; i < words.size(); i++)
        {
            if (visited[i])
                continue;
            
            if (CanTransform(temp, words[i]))
            {
                visited[i] = true;
                q.push({ words[i], num + 1 });
            }
        }
    }
}

int main()
{
    string b = "hit";
    string t = "cog";
    vector<string> words = {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    cout << solution(b, t, words) << "\n";

    return 0;
}