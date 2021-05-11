#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& arr, int xOffset, int yOffset, int Size, vector<int>& answer)
{
    bool one = true;
    bool zero = true;
    for (int i = yOffset; i < Size + yOffset; i++)
    {
        for (int j = xOffset; j < Size + xOffset; j++)
        {
            if (arr[i][j] == 0)
                one = false;

            if (arr[i][j] == 1)
                zero = false;
        }
    }

    if (zero)
    {
        answer[0]++;
        return;
    }

    if (one)
    {
        answer[1]++;
        return;
    }


    DFS(arr, xOffset, yOffset, Size / 2, answer);
    DFS(arr, xOffset + Size / 2, yOffset, Size / 2, answer);
    DFS(arr, xOffset, yOffset + Size / 2, Size / 2, answer);
    DFS(arr, xOffset + Size / 2, yOffset + Size / 2, Size / 2, answer);
}

vector<int> solution(vector<vector<int>> arr) 
{
    vector<int> answer(2, 0);
    DFS(arr, 0, 0, arr.size(), answer);

    return answer;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 1},
        {1, 1, 1, 1}
    };

    vector<int> ans = solution(arr);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}