#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    map<char, int> m;
    for (int i = 0; i < skill.length(); i++)
        m[skill[i]] = i;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        string skill_tree = skill_trees[i];
        int cnt = 0;
        bool violates = false;
        for (auto s : skill_tree)
        {
            if (m.count(s) && m[s] == cnt)
                cnt++;
            else if(m.count(s) && m[s] != cnt)
            {
                violates = true;
                break;
            }
        }

        if (!violates)
            answer++;
    }

    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};

    cout << solution(skill, skill_trees) << "\n";

    return 0;
}