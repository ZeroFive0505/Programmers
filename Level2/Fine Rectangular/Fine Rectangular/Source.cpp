#include <iostream>

using namespace std;

long long GCD(int w, int h)
{
    while (w != 0 && h != 0)
    {
        if (w > h)
            w -= h;
        else
            h -= w;
    }

    if (w == 0)
        return h;
    else
        return w;
}

long long solution(int w, int h) 
{
    long long answer = 1;
    long long gcd = GCD(w, h);

    answer = (long long)w * (long long)h - ((long long)w / gcd + (long long)h / gcd - 1) * gcd;

    return answer;
}

int main()
{
    while (1)
    {
        int w, h;
        cin >> w >> h;

        cout << solution(w, h) << "\n";

    }

    return 0;
}