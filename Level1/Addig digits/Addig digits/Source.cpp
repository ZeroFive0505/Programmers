#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int r;
    while (n)
    {
        r = n % 10;
        n /= 10;
        answer += r;
    }

    return answer;
}

int main()
{
    int N;
    while (1)
    {
        cin >> N;
        cout << solution(N) << "\n";
    }

	return 0;
}