#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool DFS(string current, vector<vector<string>>& tickets, vector<string>& answer, vector<bool>& visited, int usedTickets)
{
    answer.push_back(current);

    if (usedTickets == tickets.size())
        return true;


    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == current && !visited[i])
        {
            visited[i] = true;

            if (DFS(tickets[i][1], tickets, answer, visited, usedTickets + 1))
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
    sort(tickets.begin(), tickets.end());
    
    vector<bool> visited(tickets.size(), false);

    DFS("ICN", tickets, answer, visited, 0);


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