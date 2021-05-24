#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) 
{
    bool answer = true;

    for (int i = 0; i < lock.size(); i++)
    {
        for (int j = 0; j < lock[i].size(); j++)
        {
            for (int rot = 0; rot < 4; rot++)
            {

            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> key = {
        {0, 0, 0},
        {1, 0, 0},
        {0, 1, 1}
    };

    vector<vector<int>> lock = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    cout << solution(key, lock) << "\n";

    return 0;
}