#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    unsigned int bit = 1;

    for (int i = 0; i < 32; i++, bit <<= 1)
    {
        if (bit & n)
            ans++;
    }

    return ans;
}

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        cout << solution(n) << "\n";
    }

    return 0;
}