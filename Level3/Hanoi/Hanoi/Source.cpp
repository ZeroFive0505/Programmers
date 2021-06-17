#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void Hanoi(int n, int src, int temp, int dest)
{
    if (n == 1)
    {
        vector<int> t;
        t.push_back(src);
        t.push_back(dest);
        answer.push_back(t);
    }
    else
    {
        Hanoi(n - 1, src, dest, temp);

        vector<int> t;
        t.push_back(src);
        t.push_back(dest);
        answer.push_back(t);


        Hanoi(n - 1, temp, src, dest);
    }
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