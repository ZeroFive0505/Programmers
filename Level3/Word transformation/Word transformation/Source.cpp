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
    vector<bool> visited(words.size(), false);
    q.push({ begin, 0 });

    while (!q.empty())
    {
        pair<string, int> f = q.front();
        q.pop();

        if (f.first == target)
        {
            answer = f.second;
            break;
        }

        for (int i = 0; i < words.size(); i++)
        {
            if (visited[i])
                continue;

            if (CanTransform(f.first, words[i]))
            {
                q.push({ words[i], f.second + 1 });
                visited[i] = true;
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
        "hot", "dot", "dog", "lot", "log"
    };

    cout << solution(b, t, words) << "\n";

    return 0;
}