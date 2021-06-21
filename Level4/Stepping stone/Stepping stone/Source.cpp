#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) 
{
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());

    long long left = 1;
    long long right = distance;

    while (left <= right)
    {
        int removeCnt = 0;

        int prevRock = 0;

        long long mid = (left + right) / 2;


        for (auto r : rocks)
        {
            if ((r - prevRock) < mid)
                removeCnt++;
            else
                prevRock = r;
        }

        if (distance - prevRock < mid)
            removeCnt++;

        if (removeCnt <= n)
        {
            answer = max((long long)answer, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return answer;
}

int main()
{
    int distance = 25;
    vector<int> rocks = { 2, 14, 11, 21, 17 };
    int n = 2;
    cout << solution(distance, rocks, n) << "\n";
    return 0;
}