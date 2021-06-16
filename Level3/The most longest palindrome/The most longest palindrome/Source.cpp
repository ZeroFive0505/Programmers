#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int solution(string s)
{
    int answer = 1;

    int size = s.size();

    while (size >= 2)
    {
        for (int i = 0; i <= s.size() - size; i++)
        {
            int left = i;
            int right = size + i - 1;
            bool palindrome = true;

            while (left <= right)
            {
                if (s[left] != s[right])
                {
                    palindrome = false;
                    break;
                }
                left++;
                right--;
            }

            if (palindrome)
                return size;
        }

        size--;
    }

    return answer;
}

int main()
{
    string s = "abacde";

    cout << solution(s) << "\n";

    return 0;
}