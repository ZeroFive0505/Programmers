#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) 
{
    long long answer = 0;

    sort(times.begin(), times.end());

    long long left = 0;
    long long right = (long long)times.back() * n;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long sum = 0;
        for (int i = 0; i < times.size(); i++)
            sum += mid / times[i];

        if (sum >= n)
        {
            answer = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
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