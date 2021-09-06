#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check(char comp, int dist, int realDist)
{
    switch (comp)
    {
    case '=':
        return dist == realDist;
    case '>':
        return realDist > dist;
    case '<':
        return realDist < dist;
    }
}

int solution(int n, vector<string> data) 
{
    int answer = 0;
    string friends = "ACFJMNRT";
    sort(friends.begin(), friends.end());
  
    do
    {
        bool match = true;
        for (int i = 0; i < data.size(); i++)
        {
            string s = data[i];

            char friendA = s[0];
            char friendB = s[2];

            char comp = s[3];
            int desireDist = s[4] - '0';

            int distA = -1;
            int distB = -1;

            for (int i = 0; i < friends.size(); i++)
            {
                if (friends[i] == friendA)
                    distA = i;

                if (friends[i] == friendB)
                    distB = i;

                if (distA != -1 && distB != -1)
                    break;
            }
            
            int currentDist = abs(distB - distA) - 1;

            if (Check(comp, desireDist, currentDist))
                continue;

            match = false;
            break;
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