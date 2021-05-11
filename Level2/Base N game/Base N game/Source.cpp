#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char HEX[16] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

string GetNBaseNum(int num, int base)
{
    int r;
    string s;

    if (num == 0)
        return "0";

    while (num)
    {
        r = num % base;
        char c = HEX[r];
        s.push_back(c);
        num /= base;
    }
    string ret(s.rbegin(), s.rend());
    return ret;
}

string solution(int n, int t, int m, int p) 
{
    string answer = "";

    int cnt = 0;
    int currentNum = 0;
    int idx = 0;
    bool skip = false;
    while (cnt != t)
    {
        string num = GetNBaseNum(currentNum, n);
        skip = false;
        if (num.size() > 1)
        {
            for (int i = 0; i < num.size(); i++)
            {
                if ((idx % m) == p - 1)
                {
                    cnt++;
                    answer += num[i];

                    if (cnt == t)
                        break;
                }

                idx++;
            }

            skip = true;
        }
        else
        {
            if ((idx % m) == p - 1)
            {
                cnt++;
                answer += num;
            }
        }
        
        if(!skip)
            idx++;
        currentNum++;
    }

    return answer;
}

int main()
{
    int n = 16;
    int t = 16;
    int m = 2;
    int p = 2;

    cout << solution(n, t, m, p) << "\n";

    return 0;
}