#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

void GetRank(int cnt, vector<int>& answer)
{
    switch (cnt)
    {
    case 6:
        answer.push_back(1);
        break;
    case 5:
        answer.push_back(2);
        break;
    case 4:
        answer.push_back(3);
        break;
    case 3:
        answer.push_back(4);
        break;
    case 2:
        answer.push_back(5);
        break;
    default:
        answer.push_back(6);
        break;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    vector<int> answer;
    set<int> max_rank;
    set<int> min_rank;


    set<int> win_numset(win_nums.begin(), win_nums.end());

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] != 0)
        {
            max_rank.insert(lottos[i]);
            min_rank.insert(lottos[i]);
        }
    }


    for (int i = 0; i < win_nums.size(); i++)
    {
        if (max_rank.size() == 6)
            break;

        if (max_rank.count(win_nums[i]) == 0)
            max_rank.insert(win_nums[i]);
    }

    for (int i = 1; i <= 45; i++)
    {
        if (min_rank.size() == 6)
            break;

        if (win_numset.count(i) == 0)
            min_rank.insert(i);
    }

    set<int>::const_iterator it;

    int cnt = 0;
    for (it = win_numset.begin(); it != win_numset.end(); it++)
    {
        if (max_rank.count(*it) != 0)
            cnt++;
    }

    GetRank(cnt, answer);

    cnt = 0;

    for (it = win_numset.begin(); it != win_numset.end(); it++)
    {
        if (min_rank.count(*it) != 0)
            cnt++;
    }

    GetRank(cnt, answer);

    return answer;
}

int main()
{
    vector<int> lottos = { 0, 0, 0, 0, 0, 0 };
    vector<int> win_nums = { 38, 19, 20, 40, 15, 25 };

    vector<int> ans = solution(lottos, win_nums);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return 0;
}