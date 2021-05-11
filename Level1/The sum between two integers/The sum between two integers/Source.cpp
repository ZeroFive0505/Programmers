#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) 
{
    long long answer = 0;

    if (b < a)
        swap(a, b);
    long long sum = 0;

    for (int i = a; i <= b; i++)
        sum += i;

    answer = sum;
    return answer;
}

int main()
{

    int a, b;

    while (1)
    {
        cin >> a >> b;
        cout << solution(a, b) << "\n";
    }

	return 0;
}