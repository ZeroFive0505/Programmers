#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 1001;

int RECT[SIZE][SIZE];

vector<int> solution(int n) 
{
    vector<int> answer;
    int row = 0;
    int col = 0;
    int num = 1;
    int dir = 0;

    for (int i = 0; i < n; i++)
    {
        switch (dir)
        {
        case 0:
            for (int j = i; j < n; j++)
                RECT[row++][col] = num++;
            row--;
            col++;
            dir = 1;
            break;
        case 1:
            for (int j = i; j < n; j++)
                RECT[row][col++] = num++;
            col -= 2;
            row--;
            dir = 2;
            break;
        case 2:
            for (int j = i; j < n; j++)
                RECT[row--][col--] = num++;
            col++;
            row += 2;
            dir = 0;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            answer.push_back(RECT[i][j]);
        }
    }

    return answer;
}

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        vector<int> ans = solution(n);

        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}