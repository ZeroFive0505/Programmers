#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool ConditionCheck(char comp, int dist, int num)
{
    if (comp == '=')
        return dist == num;
    else if (comp == '>')
        return dist > num;
    else if (comp == '<')
        return dist < num;
}

int solution(int n, vector<string> data) 
{
    int answer = 0;
    string friends = "ACFJMNRT";

    do
    {
        int size = data.size();
        bool match = true;
        for (int i = 0; i < size; i++)
        {
            string d = data[i];
            char a = d[0];
            int aPos = friends.find(a);
            char b = d[2];
            int bPos = friends.find(b);
            char c = d[3];
            int dist = d[4] - '0';

            int diff = abs(aPos - bPos) - 1;

            if (!ConditionCheck(c, diff, dist))
            {
                match = false;
                break;
            }
        }

        if (match)
            answer++;

    } while (next_permutation(friends.begin(), friends.end()));


    return answer;
}

int main()
{
    vector<string> d = {
        {"N~F=0"},
        {"R~T>2"}
    };

    int n = 2;

    cout << solution(n, d) << "\n";

    return 0;
}