#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(char comp, int dist, int realDist)
{
    switch (comp)
    {
    case '=':
        return dist == realDist;
        break;
    case '>':
        return realDist > dist;
        break;
    case '<':
        return realDist < dist;
        break;
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
        for (int i = 0; i < n; i++)
        {
            string d = data[i];
            char friendA = d[0];
            char friendB = d[2];

            char comp = d[3];

            char dist = d[4];

            
            int realDist = friends.find(friendA) - friends.find(friendB);
            realDist = abs(realDist) - 1;

            if (check(comp, dist - '0', realDist))
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
        {"M~C<2"},
        {"C~M>1"}
    };

    int n = 2;

    cout << solution(n, d) << "\n";

    return 0;
}