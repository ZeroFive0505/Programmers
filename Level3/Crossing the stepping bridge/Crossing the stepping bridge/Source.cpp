#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool CanAcross(const vector<int>& stones, const int mid, const int k)
{
    int cnt = 0;

    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - mid < 0)
            cnt++;
        else
            cnt = 0;

        if (cnt >= k)
            return false;
    }

    return true;
}

int solution(vector<int> stones, int k) 
{
    int answer = 0;

    int left = 1;
    int right = *max_element(stones.begin(), stones.end());

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (CanAcross(stones, mid, k))
        {
            answer = max(answer, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return answer;
}

int main()
{
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    int k = 3;

    cout << solution(stones, k) << "\n";

    return 0;
}