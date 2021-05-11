#include <iostream>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    int nCnt = 0;
    unsigned int bit = 1;

    for (int i = 0; i < 32; i++, bit <<= 1)
    {
        if (bit & n)
            nCnt++;
    }

    for (int i = n + 1; ; i++)
    {
        bit = 1;
        int next_cnt = 0;
        for (int j = 0; j < 32; j++, bit <<= 1)
        {
            if (i & bit)
                next_cnt++;
        }

        if (next_cnt == nCnt)
        {
            answer = i;
            break;
        }
    }

    return answer;
}

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        cout << solution(n) << "\n";
    }

    return 0;
}