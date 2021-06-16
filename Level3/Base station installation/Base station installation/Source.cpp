#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int idx = 0;

    for (int i = 1; i <= n;)
    {
        if (idx < stations.size() && i >= stations[idx] - w && i <= stations[idx] + w)
        {
            i = stations[idx] + w;
            idx++;
            i++;
        }
        else
        {
            i += (w * 2) + 1;
            answer++;
        }
    }

    return answer;
}

int main()
{
    int n = 11;
    vector<int> stations = { 4, 11 };
    int w = 1;

    cout << solution(n, stations, w) << "\n";

    return 0;
}