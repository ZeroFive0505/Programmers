#include <iostream>
#include <cmath>

using namespace std;

    
int answer = 0;
void DFS(int star, int plus)
{
    if (star < 1 || 2 * log(star) / log(3) < plus)
        return;

    if (star == 3)
    {
        if (plus == 2)
            answer++;
        return;
    }

    if (star % 3 == 0 && plus >= 2)
        DFS(star / 3, plus - 2);

    DFS(star - 1, plus + 1);
}

int solution(int n) 
{
    answer = 0;
    DFS(n - 2, 2);
    return answer;
}

int main()
{
    int n = 2147483647;

    cout << solution(n) << "\n";

    return 0;
}