#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(vector<vector<string>>& tickets, vector<bool>& visited, string current, int usedTickets, vector<string>& answer)
{
    answer.push_back(current);

    if (tickets.size() == usedTickets)
        return true;


    for (int i = 0; i < tickets.size(); i++)
    {
        string from = tickets[i][0];
        string to = tickets[i][1];

        if (from == current && !visited[i])
        {
            visited[i] = true;
            if(DFS(tickets, visited, to, usedTickets + 1, answer))
                return true;
            visited[i] = false;
        }
    }

    answer.pop_back();

    return false;
}

vector<string> solution(vector<vector<string>> tickets) 
{
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    DFS(tickets, visited, "ICN", 0, answer);
    return answer;
}

int main()
{
    vector<vector<string>> tickets = {
        {"ICN", "JFK"},
        {"HND", "IAD"},
        {"JFK", "HND"}
    };

    vector<string> ans = solution(tickets);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}