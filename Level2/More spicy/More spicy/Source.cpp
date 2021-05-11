#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int Formular(int theLeast, int theSecond)
{
    return theLeast + (theSecond * 2);
}

int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto i : scoville)
        pq.push(i);

    int cnt = 1;
    int sum;
    while (pq.size() >= 2)
    {
        int theLeast = pq.top();
        pq.pop();
        int theSecond = pq.top();
        pq.pop();

        sum = Formular(theLeast, theSecond);

        pq.push(sum);

        if (pq.top() > K)
            break;

        cnt++;
    }

    if (pq.top() > K)
        answer = cnt;
    else
        answer = -1;
    

    return answer;
}

int main()
{
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    int K = 7;

    cout << solution(scoville, K) << "\n";

    return 0;
}