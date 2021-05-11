#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    map<string, int> m;
    int turn = 1;
    int idx = 0;
    char lastCh = ' ';
    while (1)
    {
        int i;
        bool lost = false;
        for (i = 0; i < n; i++)
        {
            int size = words.size();
            string w = words[idx++ % size];
            if (lastCh != ' ' && lastCh != w[0])
            {
                lost = true;
                break;
            }


            if (m[w] != 0)
            {
                lost = true;
                break;
            }
            else
                m[w] = 1;

            lastCh = w.back();
        }

        if (lost)
        {
            answer.push_back(i + 1);
            answer.push_back(turn);
            break;
        }
        else if (idx >= words.size())
        {
            answer.push_back(0);
            answer.push_back(0);
            break;
        }

        turn++;
    }

    return answer;
}

int main()
{
    int n = 2;
    vector<string> w = {"hello", "one", "even", "never", "now", "world", "draw"};

    vector<int> ans = solution(n, w);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";


    return 0;
}