#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int DIV = 1234567;

int solution(int n) 
{
    int answer = 0;
    
    if (n <= 1)
        return n;

    int first = 0;
    int last = 1;

    for (int i = 2; i <= n; i++)
    {
        int sum = (first + last) % DIV;
        first = last;
        last = sum;
    }

    answer = last;
    return answer;
}

int main()
{
    int n = 3;
    cout << solution(n) << "\n";
    return 0;
}