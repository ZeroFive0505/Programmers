#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    for (int len = 0; len < commands.size(); len++)
    {
        vector<int> comm = commands[len];
        int i = comm[0];
        int j = comm[1];
        int k = comm[2];

        vector<int> temp(array.begin() + (i - 1), array.begin() + j);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k - 1]);
    }

    return answer;
}

int main()
{
    vector<int> arr = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = {
        {2, 5, 3},
        {4, 4, 1},
        {1, 7, 3}
    };

    solution(arr, commands);
    return 0;
}