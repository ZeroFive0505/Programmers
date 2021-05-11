#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;
    vector<vector<int>> m(rows, vector<int>(columns, 0));

    int cnt = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            m[i][j] = cnt++;
        }
    }

    for (int i = 0; i < queries.size(); i++)
    {
        vector<int> q = queries[i];
        vector<int> v;
        vector<pair<int, int>> coords;
        int x1 = q[0] - 1;
        int y1 = q[1] - 1;
        int x2 = q[2] - 1;
        int y2 = q[3] - 1;

        for (int j = y1; j < y2; j++)
        {
            v.push_back(m[x1][j]);
            coords.push_back({ x1, j });
        }

        for (int j = x1; j < x2; j++)
        {
            v.push_back(m[j][y2]);
            coords.push_back({ j, y2 });
        }

        for (int j = y2; j > y1; j--)
        {
            v.push_back(m[x2][j]);
            coords.push_back({ x2, j });
        }

        for (int j = x2; j > x1; j--)
        {
            v.push_back(m[j][y1]);
            coords.push_back({ j, y1 });
        }

        answer.push_back(*min_element(v.begin(), v.end()));

        int last = v.back();
        int size = v.size();

        stack<int> s;
        s.push(v[0]);

        for (int i = 1; i < size; i++)
        {
            int top = s.top();
            s.push(v[i]);
            v[i] = top;
        }

        v[0] = last;

        for (const auto& kv : coords)
        {
            m[kv.first][kv.second] = v[0];
            v.erase(v.begin());
        }

    }

    return answer;
}

int main()
{
    int r = 3;
    int c = 3;
    vector<vector<int>> q = {
        {1, 1, 2, 2},
        {1, 2, 2, 3},
        {2, 1, 3, 2},
        {2, 2, 3, 3}
    };

    vector<int> ans = solution(r, c, q);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}