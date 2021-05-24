#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) 
{
    long long answer = 0;

    sort(times.begin(), times.end());

    long long maxTime = (long long)times.back() * n;
    long long minTime = 0;

    while (minTime <= maxTime)
    {
        long long mid = (maxTime + minTime) / 2;

        long long sum = 0;

        for (int i = 0; i < times.size(); i++)
            sum += mid / times[i];

        if (sum >= n)
        {
            maxTime = mid - 1;
            answer = mid;
        }
        else if (sum < n)
            minTime = mid + 1;
    }

    return answer;
}

int main()
{
    int n = 6;
    vector<int> t = { 7, 10 };

    cout << solution(n, t) << "\n";

    return 0;
}