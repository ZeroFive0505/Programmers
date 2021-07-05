#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 300001;


int cache[MAX][2]; // 0: 워크숍 참석 X, 1: 워크숍 참석
vector<int> Node[MAX];
vector<int> Cost;

void DFS(int cur)
{
    bool leaf_node = true;

    for (int i = 0; i < Node[cur].size(); i++)
    {
        int next = Node[cur][i];
        // 만약 자식이 하나라도 있으면 리프노드가 아니다.
        leaf_node = false;
        // 재귀 탐색
        DFS(next);
    }

    if (leaf_node)
    {
        // 리프노드일경우 참석을 안 했을때는 0, 참석했을시에는 그 비용만큼이 된다.
        cache[cur][0] = 0;
        cache[cur][1] = Cost[cur - 1];
        return;
    }

    // 리프노드가 아닐경우 즉, 팀장과 팀원의 역활을 동시에 하는 노드.
    int sum = 0;
    int min_cost = 987654321;
    bool attend = true;

    for (int i = 0; i < Node[cur].size(); i++)
    {
        int child = Node[cur][i];
        sum += min(cache[child][0], cache[child][1]);
        if (cache[child][0] >= cache[child][1])
            attend = false;
        min_cost = min(min_cost, cache[child][1] - cache[child][0]);
    }

    cache[cur][1] = Cost[cur - 1] + sum;
    if (attend == false)
        cache[cur][0] = sum;
    else
        cache[cur][0] = sum + min_cost;
}

int solution(vector<int> sales, vector<vector<int>> links) 
{
    int answer = 0;

    for (int i = 0; i < links.size(); i++)
    {
        int parent = links[i][0];
        int child = links[i][1];
        Node[parent].push_back(child);
    }

    Cost = sales;
    DFS(1);

    answer = min(cache[1][0], cache[1][1]);


    return answer;
}

int main()
{
    vector<int> sales = { 14, 17, 15, 18, 19, 14, 13, 16, 28, 17 };
    vector<vector<int>> links = {
        {10, 8},
        {1, 9},
        {9, 7},
        {5, 4},
        {1, 5},
        {5, 10},
        {10, 6},
        {1, 3},
        {10, 2}
    };

    cout << solution(sales, links) << "\n";

    return 0;
}