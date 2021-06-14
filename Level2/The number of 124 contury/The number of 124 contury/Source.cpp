#include <iostream>
#include <string>

using namespace std;

const int SIZE = 3;

const char convert[SIZE] = { '1', '2', '4' };

string solution(int n) 
{
    string answer = "";

    while (n)
    {
        n -= 1;

        char c = convert[n % SIZE];

        answer = c + answer;

        n /= SIZE;
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