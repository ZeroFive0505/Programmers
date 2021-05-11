#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    vector<int> gym_suit(n, 1);

    for (int i = 0; i < lost.size(); i++)
        gym_suit[lost[i] - 1]--;

    for (int i = 0; i < reserve.size(); i++)
        gym_suit[reserve[i] - 1]++;

    for (int i = 0; i < gym_suit.size(); i++)
    {
        if (gym_suit[i] == 0)
        {
            if (i == 0)
            {
                int next = gym_suit[i + 1];
                if (next > 1)
                {
                    n++;
                    gym_suit[i]++;
                    gym_suit[i + 1]--;
                }
            }
            else if(i == (gym_suit.size() - 1))
            {
                int before = gym_suit[i - 1];
                if (before > 1)
                {
                    n++;
                    gym_suit[i]++;
                    gym_suit[i - 1]--;
                }
            }
            else
            {
                int before = gym_suit[i - 1];
                int next = gym_suit[i + 1];

                if (before > 1)
                {
                    gym_suit[i - 1]--;
                    gym_suit[i]++;
                }
                else if (next > 1)
                {
                    gym_suit[i + 1]--;
                    gym_suit[i]++;
                }
            }
        }
    }
    
    for (int i = 0; i < gym_suit.size(); i++)
    {
        if (gym_suit[i] != 0)
            answer++;
    }

    return answer;
}

int main()
{
    vector<int> lost{ 2, 4 };
    vector<int> reserve{ 3 };
    cout << solution(5, lost, reserve);
    return 0;
}