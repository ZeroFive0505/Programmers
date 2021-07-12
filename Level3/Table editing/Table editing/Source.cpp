#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;


string solution(int n, int k, vector<string> cmd)
{
    string answer;
    for (int i = 0; i < n; i++)
        answer.push_back('X');
    list<int> rows;
    stack<pair<int, int>> rewind;

    for (int i = 0; i < n; i++)
        rows.push_back(i);

    list<int>::iterator it = rows.begin();
    list<int>::iterator temp;

    for (int i = 0; i < k; i++)
        it++;

    for (int i = 0; i < cmd.size(); i++)
    {
        string order = cmd[i];

        if (order.size() == 1)
        {
            switch (order[0])
            {
            case 'C':
                temp = it;
                if (*it != 0)
                {
                    temp--;
                    rewind.push({ *temp, *it });
                    temp++;
                }
                else if (*it == 0)
                    rewind.push({ -1, 0 });

                it++;
                if (it == rows.end())
                {
                    for (int j = 0; j < 2; j++)
                        it--;
                }
                rows.erase(temp);
                break;
            case 'Z':
                pair<int, int> t = rewind.top();
                rewind.pop();
                temp = rows.begin();
                if (t.first != -1)
                {
                    while (*temp != t.first)
                        temp++;
                    temp++;
                    rows.insert(temp, t.second);
                }
                else if (t.first == -1)
                    rows.insert(temp, t.second);
                break;
            }
        }
        else
        {
            char c = 0;
            int num = 0;

            for (int j = 0; j < order.size(); j++)
            {
                if (isalpha(order[j]))
                    c = order[j];

                if (isdigit(order[j]))
                    num = num * 10 + order[j] - '0';
            }

            switch (c)
            {
            case 'U':
                for (int j = 0; j < num; j++)
                    it--;
                break;
            case 'D':
                for (int j = 0; j < num; j++)
                    it++;
                break;
            }
        }
    }

    for (it = rows.begin(); it != rows.end(); it++)
        answer[*it] = 'O';

    return answer;
}

int main()
{
    int n = 8;
    int k = 2;
    vector<string> cmd = {
       "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"
    };

    cout << solution(n, k, cmd) << "\n";

    return 0;
}