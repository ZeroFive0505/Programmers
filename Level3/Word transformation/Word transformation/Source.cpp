#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool CanTransform(string a, string b)
{
    int diff = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            diff++;
    }

    if (diff == 1)
        return true;
    else
        return false;
}

int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
    queue<pair<string, int>> q;

    q.push({ begin, 0 });

    vector<bool> check(words.size(), false);

    while (!q.empty())
    {
        pair<string, int> temp = q.front();
        q.pop();
        string tf = temp.first;
        int cnt = temp.second;

        if (tf == target)
        {
            answer = cnt;
            break;
        }

        for (int i = 0; i < words.size(); i++)
        {
            if (check[i])
                continue;

            if (CanTransform(tf, words[i]))
            {
                check[i] = true;
                q.push({ words[i], cnt + 1 });
            }
        }
    }

    return answer;
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