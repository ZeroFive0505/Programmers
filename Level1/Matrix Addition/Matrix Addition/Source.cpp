#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer;
    vector<int> temp;
    int row = arr1.size();

    for (int r = 0; r < row; r++)
    {
        vector<int>::iterator it1;
        vector<int>::iterator it2;

        it1 = arr1[r].begin();
        it2 = arr2[r].begin();

        while (it1 != arr1[r].end() && it2 != arr2[r].end())
        {
            int sum = *it1 + *it2;
            temp.push_back(sum);
            it1++;
            it2++;
        }

        answer.push_back(temp);
        temp.clear();
    }

    return answer;
}

int main()
{
    vector<vector<int>> arr1 = {
        {1, 2},
        {2, 3}
    };

    vector<vector<int>> arr2 = {
        {3, 4},
        {5, 6}
    };

    vector<vector<int>> s = solution(arr1, arr2);

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}