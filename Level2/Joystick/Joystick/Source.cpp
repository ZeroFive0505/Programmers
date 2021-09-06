#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int solution(string name) 
{
    int answer = 0;

    int shifts = name.size() - 1;

    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == 'A')
        {
            int lastA = i;
            while (lastA < name.size() && name[lastA] == 'A')
                lastA++;

            int left = lastA == 0 ? 0 : i - 1;
            int right = name.size() - lastA;
            shifts = min(shifts, left + right + min(left, right));
        }
    }

   
    for (int i = 0; i < name.size(); i++)
    {
        shifts += min(name[i] - 'A', 'Z' - name[i] + 1);
    }

    answer = shifts;

    return answer;
}

int main()
{
    string name = "JEROEN";

    cout << solution(name) << "\n";

    return 0;
}