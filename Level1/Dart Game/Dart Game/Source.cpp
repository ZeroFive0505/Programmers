#include <iostream>
#include <string>
#include <ctype.h>
#include <cmath>

using namespace std;

int SDT(int num, char c)
{
    switch (c)
    {
    case 'S':
        return pow(num, 1);
    case 'D':
        return pow(num, 2);
    case 'T':
        return pow(num, 3);
    }
}

int solution(string dartResult) 
{
    int answer = 0;
    int score[3] = { 0, 0, 0 };
    int bonus[3] = { 1, 1, 1 };
    int len = dartResult.length();
    string t;
    int scoreIndex = 0;
    for (int i = 0; i < len; i++)
    {
        char c = dartResult[i];
        if (isdigit(c))
            t += c;
        else if (isalpha(c))
        {
            int num = stoi(t);
            t.clear();

            if ((i + 1) < len && (dartResult[i + 1] == '#' || dartResult[i + 1] == '*'))
            {
                char b = dartResult[i + 1];

                if (b == '#')
                    bonus[scoreIndex] = -1;
                else if (b == '*')
                {
                    if (scoreIndex >= 1)
                        bonus[scoreIndex - 1] *= 2;
                       
                    bonus[scoreIndex] *= 2;
                }
            }  

            score[scoreIndex++] = SDT(num, c);
        }
    }

    answer = (score[0] * bonus[0]) + (score[1] * bonus[1]) + (score[2] * bonus[2]);
    return answer;
}

int main()
{
    string dartResult = "1T2D3D#";
    cout << solution(dartResult) << "\n";
    return 0;
}