#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) 
{
    int answer = 0;
    long long n = num;
    while (n != 1)
    {
        if (answer >= 500)
        {
            answer = -1;
            break;
        }

        if (n % 2 == 0)
        {
            n /= 2;
            answer++;
        }
        else if (n % 2 == 1)
        {
            n = (n * 3) + 1;
            answer++;
        }
    }

    return answer;
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