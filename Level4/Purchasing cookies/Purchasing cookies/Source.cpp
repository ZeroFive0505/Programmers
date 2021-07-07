#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) 
{
    int answer = 0;
    
    for (int i = 0; i < cookie.size() - 1; i++)
    {
        int left = cookie[i];
        int right = cookie[i + 1];

        int left_idx = i;
        int right_idx = i + 1;

        while (1)
        {
            if (left == right)
                answer = max(answer, left);

            if (left > right)
            {
                if (right_idx + 1 == cookie.size())
                    break;
                right += cookie[++right_idx];
            }
            else
            {
                if (left_idx - 1 < 0)
                    break;
                left += cookie[--left_idx];
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> cookie = {
        1, 1, 2, 3
    };

    cout << solution(cookie) << "\n";

    return 0;
}