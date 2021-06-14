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

void DFS(vector<string>& user_id, vector<string>& banned_id, int idx, int n, int len)
{
    if (idx == len)
    {
        s.insert(n);
        return;
    }

    for (int i = 0; i < user_id.size(); i++)
    {

        int j;

        if (user_id[i].size() != banned_id[idx].size())
            continue;

        if (check[i])
            continue;

        for (j = 0; j < user_id[i].size(); j++)
        {
            if (banned_id[idx][j] == '*')
                continue;

            if (user_id[i][j] != banned_id[idx][j])
                break;
        }

        if (j == user_id[i].size())
        {
            check[i] = true;
            DFS(user_id, banned_id, idx + 1, n | (1 << i), len);
            check[i] = false;
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
        "frodo", "fradi", "crodo", "abc123", "frodoc"
    };

    vector<string> banned_id = {
        "fr*d*", "abc1**"
    };

    cout << solution(user_id, banned_id) << "\n";

    return 0;
}