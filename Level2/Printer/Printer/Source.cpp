#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    int answer = 0;
    list<pair<int, int>> jobs;
    vector<pair<int, int>> prints;
    pair<int, int> target = { priorities[location], location };

    for (int i = 0; i < priorities.size(); i++)
        jobs.push_back({ priorities[i], i });


    while (!jobs.empty())
    {
        pair<int, int> f = jobs.front();
        jobs.pop_front();
        list<pair<int, int>>::iterator it;
        bool top = true;
        for (it = jobs.begin(); it != jobs.end(); it++)
        {
            if (f.first < (*it).first)
            {
                jobs.push_back(f);
                top = false;
                break;
            }
        }

        if (top)
            prints.push_back(f);
    }

    for (int i = 0; i < prints.size(); i++)
    {
        if (prints[i] == target)
        {
            answer = i + 1;
            break;
        }
    }


    return answer;
}

int main()
{
    vector<int> p = { 1, 1, 9, 1, 1, 1 };
    int location = 0;

    cout << solution(p, location) << "\n";

    return 0;
}