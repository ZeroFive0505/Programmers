#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const int SIZE = 9;

bool check[SIZE];

set<int> s;

void DFS(vector<string>& user_id, vector<string>& banned_id, int i, int num, int len)
{
    if (i == len)
    {
        s.insert(num);
        return;
    }

    for (int j = 0; j < user_id.size(); j++)
    {
        int k;

        if (user_id[j].size() != banned_id[i].size())
            continue;

        if (check[j])
            continue;

        for (k = 0; k < user_id[j].size(); k++)
        {
            if (banned_id[i][k] == '*')
                continue;
            
            if (user_id[j][k] != banned_id[i][k])
                break;
        }

        if (k == user_id[j].size())
        {
            check[j] = true;
            DFS(user_id, banned_id, i + 1, num | (1 << j), len);
            check[j] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
    int answer = 0;
    DFS(user_id, banned_id, 0, 0, banned_id.size());
    answer = s.size();
    return answer;
}

int main()
{
    vector<string> user_id = {
        "frodo",
        "frodi",
        "crodo",
        "abc123",
        "frodoc"
    };

    vector<string> banned_id = {
        "fr*d*",
        "*rodo",
        "******",
        "******"
    };

    cout << solution(user_id, banned_id) << "\n";

    return 0;
}