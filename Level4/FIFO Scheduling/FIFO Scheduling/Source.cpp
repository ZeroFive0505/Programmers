#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;

int solution(int n, vector<int> cores) 
{
    int answer = 0;
    
    if(n <= cores.size())
        return n;

    int m = *min_element(cores.begin(), cores.end());

    int left = n / cores.size() * m;
    int right = n * m;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int cnt = cores.size();

        int currentCnt = 0;

        for (int i = 0; i < cores.size(); i++)
        {
            cnt += mid / cores[i];
            if (mid % cores[i] == 0)
            {
                cnt--;
                currentCnt++;
            }
        }

        if (cnt >= n)
        {
            right = mid - 1;
        }
        else if ((cnt + currentCnt) < n)
            left = mid + 1;
        else
        {
            for (int i = 0; i < cores.size(); i++)
            {
                if (mid % cores[i] == 0)
                    cnt++;

                if (cnt == n)
                    return i + 1;
            }
        }
    }


    return answer;
}

int main()
{
    vector<int> cores = {
        1, 2, 3
    };

    int n = 6;

    cout << solution(n, cores) << "\n";

    return 0;
}