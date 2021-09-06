#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void Hanoi(int n, int src, int temp, int dest)
{
    if (n == 1)
    {
        answer.push_back({ src, dest });
        return;
    }

    Hanoi(n - 1, src, dest, temp);
    answer.push_back({ src, dest });
    Hanoi(n - 1, temp, src, dest);
}

vector<vector<int>> solution(int n) 
{
    Hanoi(n, 1, 2, 3);
    return answer;
}

int main()
{
    int n = 2;

    vector<vector<int>> ans = solution(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}