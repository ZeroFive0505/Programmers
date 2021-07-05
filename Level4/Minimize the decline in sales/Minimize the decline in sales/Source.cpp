#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 300001;


int cache[MAX][2]; // 0: ��ũ�� ���� X, 1: ��ũ�� ����
vector<int> Node[MAX];
vector<int> Cost;

void DFS(int cur)
{
    bool leaf_node = true;

    for (int i = 0; i < Node[cur].size(); i++)
    {
        int next = Node[cur][i];
        // ���� �ڽ��� �ϳ��� ������ ������尡 �ƴϴ�.
        leaf_node = false;
        // ��� Ž��
        DFS(next);
    }

    if (leaf_node)
    {
        // ��������ϰ�� ������ �� �������� 0, ���������ÿ��� �� ��븸ŭ�� �ȴ�.
        cache[cur][0] = 0;
        cache[cur][1] = Cost[cur - 1];
        return;
    }

    // ������尡 �ƴҰ�� ��, ����� ������ ��Ȱ�� ���ÿ� �ϴ� ���.
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