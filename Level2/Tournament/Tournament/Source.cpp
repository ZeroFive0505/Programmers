#include <iostream>
#include <vector>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    vector<bool> v;

    for (int i = 1; i <= n; i++)
    {
        if (i == a || i == b)
            v.push_back(true);
        else
            v.push_back(false);
    }

    while (v.size() >= 2)
    {

        vector<bool> t;
        bool found = false;
        for (int i = 0; i < v.size(); i += 2)
        {
            if (v[i] && v[i + 1])
            {
                found = true;
                break;
            }
            else if (v[i] == false && v[i + 1] == false)
                t.push_back(v[i]);
            else if (v[i] && v[i + 1] == false)
                t.push_back(v[i]);
            else if (v[i] == false && v[i + 1])
                t.push_back(v[i + 1]);
        }

        answer++;

        if (found)
            break;

        v = t;
    }

    return answer;
}

int main()
{
    int n = 8;
    int a = 1;
    int b = 8;

    cout << solution(n, a, b) << "\n";

    return 0;
}