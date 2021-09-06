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
        n--;
        int index = n % SIZE;
        answer = convert[index] + answer;
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