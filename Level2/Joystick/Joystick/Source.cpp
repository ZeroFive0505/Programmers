#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int solution(string name) 
{
    int answer = 0;

    int moves = name.length() - 1;

    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == 'A')
        {
            int Apos = i;

            while (Apos < name.length() && name[Apos] == 'A')
                Apos++;
            int BPos = Apos;
            int left = i == 0 ? 0 : i - 1;
            int right = name.length() - BPos;

            moves = min(moves, left + right + min(left, right));
        }
    }

    for (auto c : name)
        moves += min(c - 'A', 'Z' - c + 1);

    answer = moves;

    return answer;
}

int main()
{
    string name = "BBAAAAAAABBBB";

    cout << solution(name) << "\n";

    return 0;
}